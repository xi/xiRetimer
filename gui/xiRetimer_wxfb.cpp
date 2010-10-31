///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "xiRetimer_wxfb.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	m_menubar1->SetMaxSize( wxSize( -1,32 ) );
	
	m_File = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_File, wxID_ANY, wxString( wxT("&open") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_open );
	
	wxMenuItem* m_export;
	m_export = new wxMenuItem( m_File, wxID_ANY, wxString( wxT("e&xport") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_export );
	
	wxMenuItem* m_separator3;
	m_separator3 = m_File->AppendSeparator();
	
	wxMenuItem* m_prefs;
	m_prefs = new wxMenuItem( m_File, wxID_ANY, wxString( wxT("preferences") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_prefs );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_File->AppendSeparator();
	
	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_File, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_exit );
	
	m_menubar1->Append( m_File, wxT("File") );
	
	m_Help = new wxMenu();
	wxMenuItem* m_help;
	m_help = new wxMenuItem( m_Help, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	m_Help->Append( m_help );
	
	wxMenuItem* m_separator1;
	m_separator1 = m_Help->AppendSeparator();
	
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_Help, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_Help->Append( m_about );
	
	m_menubar1->Append( m_Help, wxT("Help") );
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( m_open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenClick ) );
	this->Connect( m_export->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportClick ) );
	this->Connect( m_prefs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPrefsClick ) );
	this->Connect( m_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExitClick ) );
	this->Connect( m_help->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnHelpClick ) );
	this->Connect( m_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAboutClick ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPrefsClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExitClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnHelpClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAboutClick ) );
}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
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
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Interpolation Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer4->Add( m_staticText3, 0, wxALL, 5 );
	
	m_choicebook1 = new wxChoicebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	fgSizer4->Add( m_choicebook1, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer4->Add( m_staticText4, 0, wxALL, 5 );
	
	m_colourPicker6 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( m_colourPicker6, 0, wxALL|wxEXPAND, 5 );
	
	bSizer5->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button3, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button2, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer5->Add( bSizer15, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	// Connect Events
	m_choicebook1->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( PrefsDialog::OnIModeChange ), NULL, this );
	m_colourPicker6->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PrefsDialog::OnColorChange ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnOKClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnCancelClick ), NULL, this );
}

PrefsDialog::~PrefsDialog()
{
	// Disconnect Events
	m_choicebook1->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( PrefsDialog::OnIModeChange ), NULL, this );
	m_colourPicker6->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PrefsDialog::OnColorChange ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnOKClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrefsDialog::OnCancelClick ), NULL, this );
}

WaitDialog::WaitDialog( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_gauge2 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	bSizer7->Add( m_gauge2, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Please wait ..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer7->Add( m_staticText5, 0, wxALL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

WaitDialog::~WaitDialog()
{
}

FileSelectDialog::FileSelectDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_filePicker2 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer9->Add( m_filePicker2, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_toggleBtn2 = new wxToggleButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_toggleBtn2, 1, wxALL|wxEXPAND, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button2, 1, wxEXPAND|wxALL, 5 );
	
	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	
	// Connect Events
	m_toggleBtn2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FileSelectDialog::OnOKClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileSelectDialog::OnCancelClick ), NULL, this );
}

FileSelectDialog::~FileSelectDialog()
{
	// Disconnect Events
	m_toggleBtn2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( FileSelectDialog::OnOKClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileSelectDialog::OnCancelClick ), NULL, this );
}
