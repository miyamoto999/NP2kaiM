///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxNP21kaiMBaseFrame
///////////////////////////////////////////////////////////////////////////////
class wxNP21kaiMBaseFrame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel1;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnShow( wxShowEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxNP21kaiMBaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxNP21kaiM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 726,541 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~wxNP21kaiMBaseFrame();

};

