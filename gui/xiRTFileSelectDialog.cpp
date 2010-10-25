#include "xiRTFileSelectDialog.h"

xiRTFileSelectDialog::xiRTFileSelectDialog( wxWindow* parent )
:
FileSelectDialog( parent )
{

}

void xiRTFileSelectDialog::OnOKClick( wxCommandEvent& event )
{
	// TODO: Implement OnOKClick
        Close();
}

void xiRTFileSelectDialog::OnCancelClick( wxCommandEvent& event )
{
	Close();
}
