#ifndef __xiRTPrefsDialog__
#define __xiRTPrefsDialog__

/**
@file
Subclass of PrefsDialog, which is generated by wxFormBuilder.
*/

#include "xiRetimer_wxfb.h"

/** Implementing PrefsDialog */
class xiRTPrefsDialog : public PrefsDialog
{
protected:
	// Handlers for PrefsDialog events.
	void OnIModeChange( wxChoicebookEvent& event );
	void OnColorChange( wxColourPickerEvent& event );
	void OnOKClick( wxCommandEvent& event );
	void OnCancelClick( wxCommandEvent& event );
	
public:
	/** Constructor */
	xiRTPrefsDialog( wxWindow* parent );
};

#endif // __xiRTPrefsDialog__
