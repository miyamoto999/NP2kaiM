///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx98keymapForms.h"

///////////////////////////////////////////////////////////////////////////

wx98keymapBase::wx98keymapBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_keywidget = new KeyWidget( this, ID_KEYMAPWIDGET, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_keywidget, 1, wxALL|wxEXPAND, 0 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("KeyCode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALL, 5 );

	m_staticKeycode = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticKeycode->Wrap( -1 );
	fgSizer1->Add( m_staticKeycode, 0, wxALL, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, _("modifiers:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	fgSizer1->Add( m_staticText20, 0, wxALL, 5 );

	m_staticModifiers = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifiers->Wrap( -1 );
	fgSizer1->Add( m_staticModifiers, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, _("RawKeyCode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL, 5 );

	m_staticRawKeyCode = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRawKeyCode->Wrap( -1 );
	fgSizer1->Add( m_staticRawKeyCode, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, _("RawKeyFlags:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL, 5 );

	m_staticRawKeyFlags = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRawKeyFlags->Wrap( -1 );
	fgSizer1->Add( m_staticRawKeyFlags, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, _("UnicodeKey:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer1->Add( m_staticText12, 0, wxALL, 5 );

	m_staticUnicodeKey = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticUnicodeKey->Wrap( -1 );
	fgSizer1->Add( m_staticUnicodeKey, 0, wxALL, 5 );


	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuOpen;
	m_menuOpen = new wxMenuItem( m_menu1, wxID_OPEN, wxString( _("&Open...") ) + wxT('\t') + wxT("Ctrl-O"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuOpen );

	wxMenuItem* m_menuSave;
	m_menuSave = new wxMenuItem( m_menu1, wxID_SAVE, wxString( _("&Save") ) + wxT('\t') + wxT("Ctrl-S"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuSave );

	wxMenuItem* m_menuSaveAs;
	m_menuSaveAs = new wxMenuItem( m_menu1, wxID_SAVEAS, wxString( _("Save &As...") ) + wxT('\t') + wxT("Shift-Ctrl-S"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuSaveAs );

	wxMenuItem* m_menuClose;
	m_menuClose = new wxMenuItem( m_menu1, wxID_CLOSE, wxString( _("&Close") ) + wxT('\t') + wxT("Ctrl-W"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuClose );

	wxMenuItem* m_menuQuit;
	m_menuQuit = new wxMenuItem( m_menu1, wxID_QUIT, wxString( _("&Quit") ) + wxT('\t') + wxT("Ctrl-Q"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuQuit );

	m_menubar1->Append( m_menu1, _("&File") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wx98keymapBase::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wx98keymapBase::OnKeyDown ) );
	this->Connect( wxEVT_KEY_UP, wxKeyEventHandler( wx98keymapBase::OnKeyUp ) );
	m_keywidget->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wx98keymapBase::OnKeyDown ), NULL, this );
	m_keywidget->Connect( wxEVT_KEY_UP, wxKeyEventHandler( wx98keymapBase::OnKeyUp ), NULL, this );
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wx98keymapBase::OnMenuOpen ), this, m_menuOpen->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wx98keymapBase::OnMenuSave ), this, m_menuSave->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wx98keymapBase::OnMenuSaveAs ), this, m_menuSaveAs->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wx98keymapBase::OnMenuClose ), this, m_menuClose->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wx98keymapBase::OnMenuQuit ), this, m_menuQuit->GetId());
}

wx98keymapBase::~wx98keymapBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wx98keymapBase::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wx98keymapBase::OnKeyDown ) );
	this->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( wx98keymapBase::OnKeyUp ) );
	m_keywidget->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wx98keymapBase::OnKeyDown ), NULL, this );
	m_keywidget->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( wx98keymapBase::OnKeyUp ), NULL, this );

}

KeyDialogBase::KeyDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Keyname:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer3->Add( m_staticText9, 1, wxALL, 5 );

	m_staticKeyname = new wxStaticText( this, wxID_ANY, _("KEY"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticKeyname->Wrap( -1 );
	fgSizer3->Add( m_staticKeyname, 0, wxALL|wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, _("key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer3->Add( m_staticText11, 0, wxALL, 5 );

	m_staticKey = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticKey->Wrap( -1 );
	fgSizer3->Add( m_staticKey, 0, wxALL, 5 );

	m_staticText22 = new wxStaticText( this, wxID_ANY, _("modifiers:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL, 5 );

	m_staticModifiers = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModifiers->Wrap( -1 );
	fgSizer3->Add( m_staticModifiers, 0, wxALL, 5 );

	m_staticText13 = new wxStaticText( this, wxID_ANY, _("rawKeyCode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer3->Add( m_staticText13, 0, wxALL, 5 );

	m_staticRawKeyCode = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRawKeyCode->Wrap( -1 );
	fgSizer3->Add( m_staticRawKeyCode, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, _("rawKeyFlags:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer3->Add( m_staticText15, 0, wxALL, 5 );

	m_staticRawKeyFlags = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRawKeyFlags->Wrap( -1 );
	fgSizer3->Add( m_staticRawKeyFlags, 0, wxALL, 5 );

	m_staticText17 = new wxStaticText( this, wxID_ANY, _("rawUnicodeKey:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer3->Add( m_staticText17, 0, wxALL, 5 );

	m_staticRawUnicodeKey = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRawUnicodeKey->Wrap( -1 );
	fgSizer3->Add( m_staticRawUnicodeKey, 0, wxALL, 5 );

	m_button1 = new wxButton( this, wxID_ANY, _("Input Key"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, _("Delete key binding"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_button2, 0, wxALL, 5 );


	bSizer4->Add( fgSizer3, 1, wxALL|wxEXPAND, 5 );

	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2->Realize();

	bSizer4->Add( m_sdbSizer2, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnInputKeyClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnDelKeyBindingClick ), NULL, this );
	m_sdbSizer2Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnCancelButtonClick ), NULL, this );
	m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnOKButtonClick ), NULL, this );
}

KeyDialogBase::~KeyDialogBase()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnInputKeyClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnDelKeyBindingClick ), NULL, this );
	m_sdbSizer2Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnCancelButtonClick ), NULL, this );
	m_sdbSizer2OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyDialogBase::OnOKButtonClick ), NULL, this );

}

InputKeyDialogBase::InputKeyDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_inputKeyControl = new wxWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_inputKeyControl, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyDialogBase::OnKeyDown ) );
	this->Connect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyDialogBase::OnKeyUp ) );
	m_inputKeyControl->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyDialogBase::OnKeyDown ), NULL, this );
	m_inputKeyControl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyDialogBase::OnKeyUp ), NULL, this );
	m_inputKeyControl->Connect( wxEVT_PAINT, wxPaintEventHandler( InputKeyDialogBase::OnInputKeyControlPaint ), NULL, this );
}

InputKeyDialogBase::~InputKeyDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyDialogBase::OnKeyDown ) );
	this->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyDialogBase::OnKeyUp ) );
	m_inputKeyControl->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyDialogBase::OnKeyDown ), NULL, this );
	m_inputKeyControl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyDialogBase::OnKeyUp ), NULL, this );
	m_inputKeyControl->Disconnect( wxEVT_PAINT, wxPaintEventHandler( InputKeyDialogBase::OnInputKeyControlPaint ), NULL, this );

}

InputKeyFrameBase::InputKeyFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_inputKeyControl = new wxWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_inputKeyControl, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( InputKeyFrameBase::OnClose ) );
	this->Connect( wxEVT_SHOW, wxShowEventHandler( InputKeyFrameBase::OnShow ) );
	m_inputKeyControl->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyFrameBase::OnKeyDown ), NULL, this );
	m_inputKeyControl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyFrameBase::OnKeyUp ), NULL, this );
	m_inputKeyControl->Connect( wxEVT_PAINT, wxPaintEventHandler( InputKeyFrameBase::OnInputKeyControlPaint ), NULL, this );
}

InputKeyFrameBase::~InputKeyFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( InputKeyFrameBase::OnClose ) );
	this->Disconnect( wxEVT_SHOW, wxShowEventHandler( InputKeyFrameBase::OnShow ) );
	m_inputKeyControl->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( InputKeyFrameBase::OnKeyDown ), NULL, this );
	m_inputKeyControl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( InputKeyFrameBase::OnKeyUp ), NULL, this );
	m_inputKeyControl->Disconnect( wxEVT_PAINT, wxPaintEventHandler( InputKeyFrameBase::OnInputKeyControlPaint ), NULL, this );

}
