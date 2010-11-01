#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"

#include <wx/progdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/string.h>
#include <wx/filedlg.h>

#include <iostream>

// TODO icon bar

xiRTMainFrame::xiRTMainFrame( wxWindow* parent ) : MainFrame( parent ) {
  curve=new Curve();
  sample=curve->sample;
  curve->setSeeker(0.7);
  curve->addMarker();
  curve->setSeeker(0.3);
  width=100; // anything greater than 2
  Marker_move=false;
}

xiRTMainFrame::~xiRTMainFrame() {}

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
  curve->setSeeker(event.m_x/(float)width);
  curve->selectMarker(-1);  //deselct
}

void xiRTMainFrame::OnLeftUp( wxMouseEvent& event ) {
  Marker_move=false;
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
  curve->setSeeker(event.m_x/(float)width);
  curve->addMarker();
}

void xiRTMainFrame::OnMotion( wxMouseEvent& event ) {
  if (Marker_move)
    curve->setMarker(event.m_x/(float)width);
}

// ************  menu  **************
void xiRTMainFrame::OnOpenClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog( (wxWindow*)NULL );
    dialog ->Show();

    if (dialog->ShowModal()==wxID_OK) {
      wxString filename=dialog->GetPath();
      sample->loadFile(filename.mb_str());
    }
}

void xiRTMainFrame::OnExportClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog((wxWindow*)NULL, _T("Export As"), _T(""), _T(""), _T("*.*"), wxSAVE | wxOVERWRITE_PROMPT);
    dialog ->Show();

    if (dialog->ShowModal()==wxID_OK) {
      wxString filename=dialog->GetPath();
      sample->process();
      sample->writeFile(filename.mb_str());
    }
}

void xiRTMainFrame::OnPrefsClick( wxCommandEvent& event )
{
    xiRTPrefsDialog* dialog = new xiRTPrefsDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnExitClick( wxCommandEvent& event )
{
  delete[] curve;
  Destroy();
}

void xiRTMainFrame::OnHelpClick( wxCommandEvent& event )
{
	// TODO: Implement OnHelpClick
}

void xiRTMainFrame::OnAboutClick( wxCommandEvent& event )
{
    xiRTAboutDialog* dialog = new xiRTAboutDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnProcessClick( wxCommandEvent& event ) {
    // TODO Link process with process bar
    wxProgressDialog::wxProgressDialog* dialog = new wxProgressDialog( _T("processing..."), _T("please wait") );
    dialog ->Show();
    sample->process();
}

void xiRTMainFrame::OnMSetClick( wxCommandEvent& event )
{
  curve->addMarker();
}

void xiRTMainFrame::OnMRmClick( wxCommandEvent& event )
{
  curve->removeMarker();
}

void xiRTMainFrame::paint() {
  // TODO dont repaint all the time
  wxClientDC dc2(this);
  int h=0;
  dc2.GetSize(&width,&h);
  wxBufferedDC dc(&dc2,wxSize(width,h));

  wxBrush brush(*wxBLACK); // red pen of width 1
  dc.SetBackground(brush);
  wxPen penCurve(*wxBLUE,1);
  wxPen penSeeker(*wxWHITE,1);
  wxPen penMarker(wxColor(255,255,0),1);
  dc.SetPen(penCurve);
  dc.Clear();
  // TODO nicer looking shape
  for (int i=0; i<width-1; ++i) {
    dc.DrawLine(i,int(curve->get(i/(float)(width-1))*h+h)/2,i+1,int(curve->get((i+1)/(float)(width-1))*h+h)/2);
  }
  // TODO display tempo bars ...
  dc.SetPen(penMarker);
  for (int i=0; i<curve->getMarkerLength(); ++i) {
    int n=int(curve->getMarker(i)*(width-1));
    dc.DrawLine(n,0,n,h);
    wxPoint ps[3];
    wxPoint p0(n-MARKERWIDTH/2,0);
    ps[0]=p0;
    wxPoint p1(n+MARKERWIDTH/2,0);
    ps[1]=p1;
    wxPoint p2(n+0,MARKERWIDTH*4/5);
    ps[2]=p2;
    dc.DrawPolygon(3,ps);
  }
  dc.SetPen(penSeeker);
  int seek=int(curve->getSeeker()*(width-1));
  dc.DrawLine(seek,0,seek,h);
}

void xiRTMainFrame::OnUpdateUI( wxUpdateUIEvent& event ) {paint();}

