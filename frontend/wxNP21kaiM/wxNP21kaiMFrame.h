#pragma once

#include "wxNP21kaiMBaseFrame.h"
#include "np2kaiapi.h"

class wxNP21kaiMFrame : public wxNP21kaiMBaseFrame
{
private:
	NP2kaiapi m_api;
	bool m_quit;

protected:
	virtual void OnClose( wxCloseEvent& event );
	virtual void OnIdle( wxIdleEvent& event );
	virtual void OnKeyDown( wxKeyEvent& event );
	virtual void OnShow( wxShowEvent& event );

public:
	wxNP21kaiMFrame(wxWindow* parent);
	~wxNP21kaiMFrame();
};

