#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"

#include <wx/progdlg.h>
#include <wx/dcclient.h>

xiRTMainFrame::xiRTMainFrame( wxWindow* parent ) : MainFrame( parent )
{

}

void xiRTMainFrame::OnOpenClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnExportClick( wxCommandEvent& event )
{
    wxFileDialog* dialog = new wxFileDialog((wxWindow*)NULL, _T("Export As"), _T(""), _T(""), _T("*.*"), wxSAVE | wxOVERWRITE_PROMPT);
    dialog ->Show();
    wxString path=dialog->GetPath();
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
  wxClientDC dc(this);
  wxBrush brush(*wxRED); // red pen of width 1
  dc.SetBackground(brush);
  dc.Clear();
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

void xiRTMainFrame::OnZUpClick( wxCommandEvent& event )
{
	// TODO: Implement OnZUpClick
}

void xiRTMainFrame::OnZDownClick( wxCommandEvent& event )
{
	// TODO: Implement OnZDownClick
}

void xiRTMainFrame::OnZFullClick( wxCommandEvent& event )
{
	// TODO: Implement OnZFullClick
}

void xiRTMainFrame::OnZSelClick( wxCommandEvent& event )
{
	// TODO: Implement OnZSelClick
}

void xiRTMainFrame::OnMSetClick( wxCommandEvent& event )
{
	// TODO: Implement OnMSetClick
}

