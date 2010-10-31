#ifndef __xiRTMainFrame__
#define __xiRTMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "xiRetimer_wxfb.h"

/** Implementing MainFrame */
class xiRTMainFrame : public MainFrame
{
protected:
	// Handlers for MainFrame events.
	void OnOpenClick( wxCommandEvent& event );
	void OnExportClick( wxCommandEvent& event );
	void OnPrefsClick( wxCommandEvent& event );
	void OnExitClick( wxCommandEvent& event );
	void OnHelpClick( wxCommandEvent& event );
	void OnAboutClick( wxCommandEvent& event );
  void OnProcessClick( wxCommandEvent& event );
	void OnZUpClick( wxCommandEvent& event );
	void OnZDownClick( wxCommandEvent& event );
	void OnZFullClick( wxCommandEvent& event );
	void OnZSelClick( wxCommandEvent& event );
	void OnMSetClick( wxCommandEvent& event );
	void OnMRmClick( wxCommandEvent& event );
	
public:
	/** Constructor */
	xiRTMainFrame( wxWindow* parent );
};

#endif // __xiRTMainFrame__
