#include "xiRTMainFrame.h"
#include "xiRTAboutDialog.h"
#include "xiRTPrefsDialog.h"
#include "xiRTFileSelectDialog.h"

xiRTMainFrame::xiRTMainFrame( wxWindow* parent )
:
MainFrame( parent )
{

}

void xiRTMainFrame::OnOpenClick( wxCommandEvent& event )
{
    xiRTFileSelectDialog* dialog = new xiRTFileSelectDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnExportClick( wxCommandEvent& event )
{
    xiRTFileSelectDialog* dialog = new xiRTFileSelectDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnPrefsClick( wxCommandEvent& event )
{
    xiRTPrefsDialog* dialog = new xiRTPrefsDialog( (wxWindow*)NULL );
    dialog ->Show();
}

void xiRTMainFrame::OnExitClick( wxCommandEvent& event )
{
	Close();
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

