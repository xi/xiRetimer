///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __retimer_wx__
#define __retimer_wx__

#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/statusbr.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/choice.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar3;
		wxMenu* m_file;
		wxMenu* m_edit;
		wxMenu* m_help;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLeftDClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnOpenClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrefsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlayClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProcessClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelpClick( wxCommandEvent& event ) { event.Skip(); }
		
	
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
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxButton* m_button1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 159,135 ), long style = wxDEFAULT_DIALOG_STYLE );
		~AboutDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PrefsDialog
///////////////////////////////////////////////////////////////////////////////
class PrefsDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* l_intmode;
		wxChoice* c_intmode;
		wxStaticText* l_stretchmode;
		wxChoice* c_stretchmode;
		wxStaticText* l_tempo;
		wxTextCtrl* t_tempo;
		wxStaticText* l_beatres;
		wxTextCtrl* t_beatres;
		wxButton* b_OK;
		wxButton* b_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIntModeChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStretchModeChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTempoEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBeatResEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PrefsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 322,238 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PrefsDialog();
	
};

#endif //__retimer_wx__
