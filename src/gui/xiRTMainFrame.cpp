#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"

#include <iostream>



xiRTMainFrame::xiRTMainFrame( wxWindow* parent ) : MainFrame( parent ) {
  marker=new Marker();
  sample=new Sample(marker);
  playback=new Playback(sample);
  curve=new Curve(marker, sample, playback);
  width=100; // anything greater than 2
  height=100;
  Marker_move=false;
  Seeker_move=false;

  brushbg=new wxBrush(*wxBLACK);
  penCurve=new wxPen(*wxBLUE,1);
  penSeeker=new wxPen(*wxWHITE,1);
  penMarker=new wxPen(wxColor(255,255,0),1);
  wxBitmap waveform;
  _updateWaveform=true;
}


xiRTMainFrame::~xiRTMainFrame() {
// TODO destroy objects
//  delete[] curve;
//  delete[] playback;
//  delete[] sample;
//  delete[] marker;
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
        _updateWaveform=true;
        return;
      }
    }
  }
  playback->setSeeker(event.m_x/(float)width);
  curve->addMarker();
}

void xiRTMainFrame::OnMotion( wxMouseEvent& event ) {
  if (Marker_move) {
    curve->setMarker(event.m_x/(float)width);
    _updateWaveform=true;
  }
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
    process();
    _updateWaveform=true;
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
  _updateWaveform=true;
}


// ************  misc  **************
void xiRTMainFrame::OnProcessClick( wxCommandEvent& event ) {process();}

void xiRTMainFrame::OnPaint( wxUpdateUIEvent& event ) {
// TODO repaint also if UI update is not necessary, eg whe seeker is moving from playback
  paint();
}

void xiRTMainFrame::OnSize( wxSizeEvent& event ) {
  _updateWaveform=true;
}


// ***********************************
void xiRTMainFrame::process() {
    sample->process();

    wxProgressDialog::wxProgressDialog* dialog = new wxProgressDialog( _T("processing..."), _T("please wait") );
    dialog ->Show();
    while (sample->getProcessing()) {
      dialog->Update(int(sample->getFinished()*100));
    }
    dialog->Show(false);
    // TODO deatroy dialog
}

void xiRTMainFrame::paint() {
  wxClientDC dc(this);
  dc.GetSize(&width,&height);
  wxBufferedDC bdc(&dc,wxSize(width,height));
  // waveform
  if (_updateWaveform) {
    waveform.Create(width, height);
    wxMemoryDC mdc;
    mdc.SelectObject(waveform);
    mdc.SetBackground(*brushbg);
    mdc.Clear();
    mdc.SetPen(*penCurve);
    for (int i=0; i<width; ++i) {
//      mdc.DrawLine(i, int(curve->get(i/(float)width)*(height-BEAT)+height)/2, i+1, int(curve->get((i+1)/(float)width)*(height-BEAT)+height)/2);
      float min=1+curve->getMin(i/(float)width, 1/(float)width);
      float max=1+curve->getMax(i/(float)width, 1/(float)width);
      mdc.DrawLine(i,int(min*height/2),i,int(max*height/2));
    }
    _updateWaveform=false;
  }
  bdc.DrawBitmap(waveform,0,0,false);
  // marker
  bdc.SetPen(*penMarker);
  for (int i=0; i<curve->getMarkerLength(); ++i) {
    int n=int(curve->getMarker(i)*(width-1));
    bdc.DrawLine(n,0,n,height);
    wxPoint ps[3];
    wxPoint p0(n-MARKERWIDTH/2,0);
    ps[0]=p0;
    wxPoint p1(n+MARKERWIDTH/2,0);
    ps[1]=p1;
    wxPoint p2(n+0,MARKERWIDTH*4/5);
    ps[2]=p2;
    bdc.DrawPolygon(3,ps);
  }
  // seeker
  bdc.SetPen(*penSeeker);
  playback->setSeeker(curve->getSeeker());
  int seek=int(curve->getSeeker()*(width-1));
  bdc.DrawLine(seek,0,seek,height);
  //beats
  bdc.SetPen(*penMarker);
  int step=int(width/curve->getBars()/curve->getBeatResolution());
  for (int i=0; i<width && step!=0; i+=step) {
    bdc.DrawLine(i,0,i,BEAT);
  }
}


