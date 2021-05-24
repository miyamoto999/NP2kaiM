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
#include "keywidget.h"
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_KEYMAPWIDGET 1000
#define wxID_QUIT 1001

///////////////////////////////////////////////////////////////////////////////
/// Class wx98keymapBase
///////////////////////////////////////////////////////////////////////////////
class wx98keymapBase : public wxFrame
{
	private:

	protected:
		KeyWidget* m_keywidget;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticKeycode;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticModifiers;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticRawKeyCode;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticRawKeyFlags;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticUnicodeKey;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuQuit( wxCommandEvent& event ) { event.Skip(); }


	public:

		wx98keymapBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wx98Keymap"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 742,449 ), long style = wxDEFAULT_FRAME_STYLE );

		~wx98keymapBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class KeyDialogBase
///////////////////////////////////////////////////////////////////////////////
class KeyDialogBase : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText9;
		wxStaticText* m_staticKeyname;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticKey;
		wxStaticText* m_staticText22;
		wxStaticText* m_staticModifiers;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticRawKeyCode;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticRawKeyFlags;
		wxStaticText* m_staticText17;
		wxStaticText* m_staticRawUnicodeKey;
		wxButton* m_button1;
		wxButton* m_button2;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Cancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInputKeyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelKeyBindingClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		KeyDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("KeyDialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 428,267 ), long style = wxDEFAULT_DIALOG_STYLE );
		~KeyDialogBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class InputKeyDialogBase
///////////////////////////////////////////////////////////////////////////////
class InputKeyDialogBase : public wxDialog
{
	private:

	protected:
		wxWindow* m_inputKeyControl;

		// Virtual event handlers, overide them in your derived class
		virtual void OnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnInputKeyControlPaint( wxPaintEvent& event ) { event.Skip(); }


	public:

		InputKeyDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 295,223 ), long style = wxDEFAULT_DIALOG_STYLE );
		~InputKeyDialogBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class InputKeyFrameBase
///////////////////////////////////////////////////////////////////////////////
class InputKeyFrameBase : public wxFrame
{
	private:

	protected:
		wxWindow* m_inputKeyControl;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnShow( wxShowEvent& event ) { event.Skip(); }
		virtual void OnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnInputKeyControlPaint( wxPaintEvent& event ) { event.Skip(); }


	public:

		InputKeyFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxSTAY_ON_TOP );

		~InputKeyFrameBase();

};

