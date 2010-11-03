#ifndef __xiRTAboutDialog__
#define __xiRTAboutDialog__

/**
@file
Subclass of AboutDialog, which is generated by wxFormBuilder.
*/

#include "xiRetimer_wxfb.h"

/** Implementing AboutDialog */
class xiRTAboutDialog : public AboutDialog
{
protected:
	// Handlers for AboutDialog events.
	void OnOKClick( wxCommandEvent& event );
	
public:
	/** Constructor */
	xiRTAboutDialog( wxWindow* parent );
};

#endif // __xiRTAboutDialog__