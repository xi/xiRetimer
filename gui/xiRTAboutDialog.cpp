#include "xiRTAboutDialog.h"

xiRTAboutDialog::xiRTAboutDialog( wxWindow* parent )
:
AboutDialog( parent )
{

}

void xiRTAboutDialog::OnOKClick( wxCommandEvent& event )
{
	Close();
}
