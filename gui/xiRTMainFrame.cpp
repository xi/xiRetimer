#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"

#include <wx/progdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/string.h>
#include <wx/filedlg.h>

xiRTMainFrame::xiRTMainFrame( wxWindow* parent ) : MainFrame( parent ) {
  curve=new Curve();
  sample=curve->sample;
  curve->setSeeker(0.3);
}

xiRTMainFrame::~xiRTMainFrame() {
  delete[] curve;
}


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
    wxProgressDialog::wxProgressDialog* dialog = new wxProgressDialog( _T("processing..."), _T("please wait") );
    dialog ->Show();
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
  // TODO BufferedDC
  wxClientDC dc2(this);
  int w=0;
  int h=0;
  dc2.GetSize(&w,&h);
  wxBufferedDC dc(&dc2,wxSize(w,h));

  wxBrush brush(*wxBLACK); // red pen of width 1
  dc.SetBackground(brush);
  wxPen penCurve(*wxBLUE,1);
  wxPen penSeeker(*wxWHITE,1);
  wxPen penMarker(wxColor(255,255,0),1);
  dc.SetPen(penCurve);
  dc.Clear();
  // TODO nicer looking shape
  for (int i=0; i<w-1; ++i) {
    dc.DrawLine(i,int(curve->get(i/(float)(w-1))*h+h)/2,i+1,int(curve->get((i+1)/(float)(w-1))*h+h)/2);
  }
  // TODO display tempo bars ...
  // TODO display marker
//  dc.SetPen(penMarker);
//  for (int i=0; i<marker->getLength(); ++i) {
//    int n=int(marker->getNew(i)*w/marker->getNew(marker->getLength()-1));
//    dc.DrawLine(n,0,n,h);
//  }
  dc.SetPen(penSeeker);
  int seek=int(curve->getSeeker()*w);
  dc.DrawLine(seek,0,seek,h);
}

void xiRTMainFrame::OnUpdateUI( wxUpdateUIEvent& event ) {paint();}

