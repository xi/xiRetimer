#include "RetimerAboutDialog.h"

RetimerAboutDialog::RetimerAboutDialog(wxWindow* parent) : AboutDialog(parent) {
}


void RetimerAboutDialog::OnOKClick(wxCommandEvent& event) {
	Close();
}
