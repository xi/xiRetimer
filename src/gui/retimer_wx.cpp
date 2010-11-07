///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "retimer_wx.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
wxInitAllImageHandlers();
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar3 = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("open") ) + wxT('\t') + wxT("CTRL+f"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_open->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/fileopen.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_open->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/fileopen.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_file->Append( m_open );
	
	wxMenuItem* m_export;
	m_export = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("export") ) + wxT('\t') + wxT("CTRL+s"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_export->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/document-save.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_export->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/document-save.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_file->Append( m_export );
	
	wxMenuItem* m_separator6;
	m_separator6 = m_file->AppendSeparator();
	
	wxMenuItem* m_prefs;
	m_prefs = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("preferences") ) + wxT('\t') + wxT("F5"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_prefs->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/document-properties.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_prefs->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/document-properties.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_file->Append( m_prefs );
	
	wxMenuItem* m_separator7;
	m_separator7 = m_file->AppendSeparator();
	
	wxMenuItem* b_exit;
	b_exit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	b_exit->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/window-close.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	b_exit->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/window-close.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_file->Append( b_exit );
	
	m_menubar3->Append( m_file, wxT("File") );
	
	m_edit = new wxMenu();
	wxMenuItem* m_play;
	m_play = new wxMenuItem( m_edit, wxID_ANY, wxString( wxT("play/pause") ) + wxT('\t') + wxT("SPACE"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_play->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-playback-start.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_play->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-playback-start.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_edit->Append( m_play );
	
	wxMenuItem* m_start;
	m_start = new wxMenuItem( m_edit, wxID_ANY, wxString( wxT("start") ) + wxT('\t') + wxT("CTRL+LEFT"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_start->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-skip-backward.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_start->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-skip-backward.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_edit->Append( m_start );
	
	wxMenuItem* m_end;
	m_end = new wxMenuItem( m_edit, wxID_ANY, wxString( wxT("end") ) + wxT('\t') + wxT("CTRL+RIGHT"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_end->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-skip-forward.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_end->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/media-skip-forward.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_edit->Append( m_end );
	
	wxMenuItem* m_separator8;
	m_separator8 = m_edit->AppendSeparator();
	
	wxMenuItem* m_clear;
	m_clear = new wxMenuItem( m_edit, wxID_ANY, wxString( wxT("clear markers") ) + wxT('\t') + wxT("CTRL+c"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_clear->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/edit-clear.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_clear->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/edit-clear.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_edit->Append( m_clear );
	
	wxMenuItem* m_process;
	m_process = new wxMenuItem( m_edit, wxID_ANY, wxString( wxT("update audio data") ) + wxT('\t') + wxT("CTRL+u"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_process->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/stock_refresh.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_process->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/stock_refresh.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_edit->Append( m_process );
	
	m_menubar3->Append( m_edit, wxT("Edit") );
	
	m_help = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_help, wxID_ANY, wxString( wxT("about") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_about->SetBitmaps( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/help-about.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_about->SetBitmap( wxBitmap( wxT("/usr/share/icons/gnome/16x16/actions/help-about.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_help->Append( m_about );
	
	m_menubar3->Append( m_help, wxT("Help") );
	
	this->SetMenuBar( m_menubar3 );
	
	
	// Connect Events
	this->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnLeftDClick ) );
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrame::OnLeftDown ) );
	this->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::OnMotion ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::OnPaint ) );
	this->Connect( m_open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenClick ) );
	this->Connect( m_export->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportClick ) );
	this->Connect( m_prefs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPrefsClick ) );
	this->Connect( b_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExitClick ) );
	this->Connect( m_play->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPlayClick ) );
	this->Connect( m_start->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnStartClick ) );
	this->Connect( m_end->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEndClick ) );
	this->Connect( m_clear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnClearClick ) );
	this->Connect( m_process->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnProcessClick ) );
	this->Connect( m_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnHelpClick ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnLeftDClick ) );
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrame::OnLeftDown ) );
	this->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::OnLeftUp ) );
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::OnMotion ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::OnPaint ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPrefsClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExitClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPlayClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnStartClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEndClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnClearClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnProcessClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnHelpClick ) );
}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("xiRetimer v0.2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer14->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Created by xi."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer14->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("www.github.com/xi"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer14->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer4->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutDialog::OnOKClick ), NULL, this );
}

AboutDialog::~AboutDialog()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutDialog::OnOKClick ), NULL, this );
}

PrefsDialog::PrefsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	l_intmode = new wxStaticText( this, wxID_ANY, wxT("Interpolation Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	l_intmode->Wrap( -1 );
	fgSizer4->Add( l_intmode, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString c_intmodeChoices[] = { wxT("Linear") };
	int c_intmodeNChoices = sizeof( c_intmodeChoices ) / sizeof( wxString );
	c_intmode = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, c_intmodeNChoices, c_intmodeChoices, 0 );
	c_intmode->SetSelection( 0 );
	fgSizer4->Add( c_intmode, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	l_stretchmode = new wxStaticText( this, wxID_ANY, wxT("Stretch Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	l_stretchmode->Wrap( -1 );
	fgSizer4->Add( l_stretchmode, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString c_stretchmodeChoices[] = { wxT("none"), wxT("RubberBand") };
	int c_stretchmodeNChoices = sizeof( c_stretchmodeChoices ) / sizeof( wxString );
	c_stretchmode = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, c_stretchmodeNChoices, c_stretchmodeChoices, 0 );
	c_stretchmode->SetSelection( 0 );
	fgSizer4->Add( c_stretchmode, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	l_tempo = new wxStaticText( this, wxID_ANY, wxT("Tempo"), wxDefaultPosition, wxDefaultSize, 0 );
	l_tempo->Wrap( -1 );
	fgSizer4->Add( l_tempo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_tempo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer4->Add( t_tempo, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	l_beatres = new wxStaticText( this, wxID_ANY, wxT("Beat Resolution"), wxDefaultPosition, wxDefaultSize, 0 );
	l_beatres->Wrap( -1 );
	fgSizer4->Add( l_beatres, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_beatres = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer4->Add( t_beatres, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer5->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	b_OK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( b_OK, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );
	
	b_Cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	b_Cancel->SetToolTip( wxT("Escape") );
	
	bSizer15->Add( b_Cancel, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer5->Add( bSizer15, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	// Connect Events
	c_intmode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PrefsDialog::OnIntModeChange ), NULL, this );
	c_stretchmode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PrefsDialog::OnStretchModeChange ), NULL, this );
	t_tempo->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PrefsDialog::OnTempoEnter ), NULL, this );
	t_beatres->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PrefsDialog::OnBeatResEnter ), NULL, this );
	b_OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnOKClick ), NULL, this );
	b_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnCancelClick ), NULL, this );
}

PrefsDialog::~PrefsDialog()
{
	// Disconnect Events
	c_intmode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PrefsDialog::OnIntModeChange ), NULL, this );
	c_stretchmode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PrefsDialog::OnStretchModeChange ), NULL, this );
	t_tempo->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PrefsDialog::OnTempoEnter ), NULL, this );
	t_beatres->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PrefsDialog::OnBeatResEnter ), NULL, this );
	b_OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnOKClick ), NULL, this );
	b_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnCancelClick ), NULL, this );
}
