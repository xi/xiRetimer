#include "xiRTPrefsDialog.h"

xiRTPrefsDialog::xiRTPrefsDialog( wxWindow* parent )
:
PrefsDialog( parent )
{

}

void xiRTPrefsDialog::OnIModeChange( wxChoicebookEvent& event )
{
	// TODO: setIMode();
}

void xiRTPrefsDialog::OnColorChange( wxColourPickerEvent& event )
{
	// TODO: setColor()
}

void xiRTPrefsDialog::OnOKClick( wxCommandEvent& event )
{
        // TODO: update();
	Close();
}

void xiRTPrefsDialog::OnCancelClick( wxCommandEvent& event )
{
	Close();
}
