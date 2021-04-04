#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wxNP21kaiMFrame.h"
#include "wxNP21kaiMApp.h"

wxNP21kaiMFrame::wxNP21kaiMFrame(wxWindow* parent):wxNP21kaiMBaseFrame(parent)
{
    m_api.load();
    m_quit = false;

    wxNP21kaiMApp& app = wxGetApp();
    
    m_api.np2api_main(app.argc, app.argv, this->m_panel1->GetHandle());
}

wxNP21kaiMFrame::~wxNP21kaiMFrame()
{
    m_api.np2api_end();
    printf("~wxNP21kaiMFrame()\n");
}

void wxNP21kaiMFrame::OnIdle( wxIdleEvent& event )
{
    if(m_quit) {
        return;
    }
    m_api.np2api_exec();
    event.RequestMore(true);
}

void wxNP21kaiMFrame::OnClose( wxCloseEvent& event )
{
    printf("OnClose\n");
    m_quit = true;
    Destroy();
}

void wxNP21kaiMFrame::OnKeyDown( wxKeyEvent& event )
{
    int keycode = event.GetKeyCode();
    wxChar unikey = event.GetUnicodeKey();
    wxUint32 rawkey = event.GetRawKeyCode();
    printf("########\n");
    printf("keycode:%u, 0x%x\n", keycode, keycode);
    printf("unikey:%u, 0x%x\n", unikey, unikey);
    printf("rawkey:%u, 0x%x\n", rawkey, rawkey);
}

void wxNP21kaiMFrame::OnShow( wxShowEvent& event )
{
}
