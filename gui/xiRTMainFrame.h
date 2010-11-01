#ifndef __xiRTMainFrame__
#define __xiRTMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "xiRetimer_wxfb.h"
#include "../src/sample.h"
#include "../src/curve.h"


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
	void OnMSetClick( wxCommandEvent& event );
	void OnMRmClick( wxCommandEvent& event );
        void OnUpdateUI( wxUpdateUIEvent& event );
        void paint();
  Sample* sample;
  Curve* curve;
	
public:
	/** Constructor */
	xiRTMainFrame( wxWindow* parent );
	~xiRTMainFrame(  );
};

#endif // __xiRTMainFrame__
