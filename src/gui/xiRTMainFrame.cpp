#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"

#include <wx/progdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/string.h>
#include <wx/filedlg.h>

#include <iostream>

// everything is living here

xiRTMainFrame::xiRTMainFrame( wxWindow* parent ) : MainFrame( parent ) {
  marker=new Marker();
  sample=new Sample(marker);
  playback=new Playback(sample);
  curve=new Curve(marker, sample, playback);
  width=100; // anything greater than 2
  height=100;
  Marker_move=false;
  Seeker_move=false;
}

xiRTMainFrame::~xiRTMainFrame() {
  delete[] curve;
  delete[] playback;
  delete[] sample;
  delete[] marker;
}

// ************  mouse  **************
void xiRTMainFrame::OnLeftDown( wxMouseEvent& event ) {
  // check for Marker Select
  if (event.m_y<=MARKERWIDTH*4/5) {
    for (int i=0; i<curve->getMarkerLength(); ++i) {
      int n=int(curve->getMarker(i)*(width-1));
      if (event.m_x<=n+MARKERWIDTH/2 && event.m_x>=n-MARKERWIDTH/2) {
        curve->selectMarker(i);
        Marker_move=true;
        return;
      }
    }
  }
  // if not returned set Seeker
  playback->setSeeker(event.m_x/(float)width);
  Seeker_move=true;
  curve->selectMarker(-1);  //deselct
}

void xiRTMainFrame::OnLeftUp( wxMouseEvent& event ) {
  Marker_move=false;
  Seeker_move=false;
}

void xiRTMainFrame::OnLeftDClick( wxMouseEvent& event ) {
  // check for Marker Select
  if (event.m_y<=MARKERWIDTH*4/5) {
    for (int i=0; i<curve->getMarkerLength(); ++i) {
      int n=int(curve->getMarker(i)*(width-1));
      if (event.m_x<=n+MARKERWIDTH/2 && event.m_x>=n-MARKERWIDTH/2) {
        curve->selectMarker(i);
        curve->removeMarker();
        return;
      }
    }
  }
  playback->setSeeker(event.m_x/(float)width);
  curve->addMarker();
}

void xiRTMainFrame::OnMotion( wxMouseEvent& event ) {
  if (Marker_move)
    curve->setMarker(event.m_x/(float)width);
  if (Seeker_move)
    playback->setSeeker(event.m_x/(float)width);
}

// ************  file  **************
void xiRTMainFrame::OnOpenClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog( (wxWindow*)NULL );
    dialog->Show();

    if (dialog->ShowModal()==wxID_OK) {
      wxString filename=dialog->GetPath();
      sample->loadFile(filename.mb_str());
    }
}

void xiRTMainFrame::OnExportClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog((wxWindow*)NULL, _T("Export As"), _T(""), _T(""), _T("*.wav"), wxSAVE | wxOVERWRITE_PROMPT);
    dialog->Show();

    if (dialog->ShowModal()==wxID_OK) {
      wxString filename=dialog->GetPath();
      sample->process();
      sample->writeFile(filename.mb_str());
    }
}

// ************  playback  **************
void xiRTMainFrame::OnStartClick( wxCommandEvent& event ) {
  playback->setSeeker(0);
}

void xiRTMainFrame::OnPlayClick( wxCommandEvent& event ) {
  playback->play();
}

void xiRTMainFrame::OnEndClick( wxCommandEvent& event ) {
  playback->setSeeker(1);
}

// ************  general  **************
void xiRTMainFrame::OnPrefsClick( wxCommandEvent& event )
{
    xiRTPrefsDialog* dialog = new xiRTPrefsDialog(marker, sample, curve);
    dialog->Show();
}

void xiRTMainFrame::OnExitClick( wxCommandEvent& event )
{
  Destroy();
}

void xiRTMainFrame::OnHelpClick( wxCommandEvent& event )
{
	// TODO: create Help
    xiRTAboutDialog* dialog = new xiRTAboutDialog( (wxWindow*)NULL );
    dialog->Show();
}

// ************  marker  **************
void xiRTMainFrame::OnClearClick( wxCommandEvent& event ) {
  curve->clearMarker();
}


// ************  misc  **************
void xiRTMainFrame::OnProcessClick( wxCommandEvent& event ) {
    // TODO Link process with process bar
/*
    wxProgressDialog::wxProgressDialog* dialog = new wxProgressDialog( _T("processing..."), _T("please wait") );
    dialog ->Show();
*/
    sample->process();
}

void xiRTMainFrame::OnUpdateUI( wxUpdateUIEvent& event ) {paint();}


// ***********************************
void xiRTMainFrame::paint() {
  // TODO dont repaint all the time
  // TODO repaint also if UI update is not necessary, eg whe seeker is moving from playback
  wxClientDC dc2(this);
  dc2.GetSize(&width,&height);
  wxBufferedDC dc(&dc2,wxSize(width,height));
  int h=height-BEAT;

  wxBrush brush(*wxBLACK);
  dc.SetBackground(brush);
  wxPen penCurve(*wxBLUE,1);
  wxPen penSeeker(*wxWHITE,1);
  wxPen penMarker(wxColor(255,255,0),1);
  dc.SetPen(penCurve);
  dc.Clear();
  for (int i=0; i<width; ++i) {
    dc.DrawLine(i,int(curve->get(i/(float)(width-1))*h+height)/2,i+1,int(curve->get((i+1)/(float)(width-1))*h+height)/2);
// TODO nicer looking shape is too slow. Should be painted on an extra buffer
/*    
    float min=curve->getMin(i/(float)width, 1/(float)width);
    float max=curve->getMax(i/(float)width, 1/(float)width);
    dc.DrawLine(i,int(min*h+height)/2,i,int(max*h+height)/2);
*/
  }
  dc.SetPen(penMarker);
  for (int i=0; i<curve->getMarkerLength(); ++i) {
    int n=int(curve->getMarker(i)*(width-1));
    dc.DrawLine(n,0,n,height);
    wxPoint ps[3];
    wxPoint p0(n-MARKERWIDTH/2,0);
    ps[0]=p0;
    wxPoint p1(n+MARKERWIDTH/2,0);
    ps[1]=p1;
    wxPoint p2(n+0,MARKERWIDTH*4/5);
    ps[2]=p2;
    dc.DrawPolygon(3,ps);
  }
  // seeker
  dc.SetPen(penSeeker);
  playback->setSeeker(curve->getSeeker());
  int seek=int(curve->getSeeker()*(width-1));
  dc.DrawLine(seek,0,seek,height);
  //beats
  dc.SetPen(penMarker);
  int step=int(width/curve->getBars()/curve->getBeatResolution());
  for (int i=0; i<width && step!=0; i+=step) {
    dc.DrawLine(i,0,i,BEAT);  
  }

}

