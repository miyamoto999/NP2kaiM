///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxNP21kaiMBaseFrame.h"

///////////////////////////////////////////////////////////////////////////

wxNP21kaiMBaseFrame::wxNP21kaiMBaseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_mnuExit;
	m_mnuExit = new wxMenuItem( m_menu1, wxID_EXIT, wxString( _("&Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_mnuExit );

	m_menubar1->Append( m_menu1, _("&File") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxNP21kaiMBaseFrame::OnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( wxNP21kaiMBaseFrame::OnIdle ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxNP21kaiMBaseFrame::OnKeyDown ) );
	this->Connect( wxEVT_SHOW, wxShowEventHandler( wxNP21kaiMBaseFrame::OnShow ) );
	m_panel1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxNP21kaiMBaseFrame::OnKeyDown ), NULL, this );
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxNP21kaiMBaseFrame::OnExit ), this, m_mnuExit->GetId());
}

wxNP21kaiMBaseFrame::~wxNP21kaiMBaseFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxNP21kaiMBaseFrame::OnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( wxNP21kaiMBaseFrame::OnIdle ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxNP21kaiMBaseFrame::OnKeyDown ) );
	this->Disconnect( wxEVT_SHOW, wxShowEventHandler( wxNP21kaiMBaseFrame::OnShow ) );
	m_panel1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxNP21kaiMBaseFrame::OnKeyDown ), NULL, this );

}
