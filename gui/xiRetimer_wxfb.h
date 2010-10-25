///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __xiRetimer_wxfb__
#define __xiRetimer_wxfb__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/choicebk.h>
#include <wx/clrpicker.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/filepicker.h>
#include <wx/tglbtn.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_File;
		wxMenu* m_Help;
		wxStatusBar* m_statusBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOpenClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrefsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelpClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAboutClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("xiRetimer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 611,397 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialog
///////////////////////////////////////////////////////////////////////////////
class AboutDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxButton* m_button1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 159,135 ), long style = wxDEFAULT_DIALOG_STYLE );
		~AboutDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PrefsDialog
///////////////////////////////////////////////////////////////////////////////
class PrefsDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxChoicebook* m_choicebook1;
		wxStaticText* m_staticText4;
		wxColourPickerCtrl* m_colourPicker6;
		wxButton* m_button3;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIModeChange( wxChoicebookEvent& event ) { event.Skip(); }
		virtual void OnColorChange( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PrefsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 247,165 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PrefsDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WaitDialog
///////////////////////////////////////////////////////////////////////////////
class WaitDialog : public wxPanel 
{
	private:
	
	protected:
		wxGauge* m_gauge2;
		wxStaticText* m_staticText5;
	
	public:
		
		WaitDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 269,80 ), long style = wxTAB_TRAVERSAL );
		~WaitDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FileSelectDialog
///////////////////////////////////////////////////////////////////////////////
class FileSelectDialog : public wxDialog 
{
	private:
	
	protected:
		wxFilePickerCtrl* m_filePicker2;
		wxToggleButton* m_toggleBtn2;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FileSelectDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 223,111 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxSTAY_ON_TOP );
		~FileSelectDialog();
	
};

#endif //__xiRetimer_wxfb__
