#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wxNP21kaiMFrame.h"
#include "wxNP21kaiMApp.h"
#include "kbddrv.h"

wxNP21kaiMFrame::wxNP21kaiMFrame(wxWindow* parent):wxNP21kaiMBaseFrame(parent)
{
    m_api.load();
    m_quit = false;

    wxNP21kaiMApp& app = wxGetApp();
    
    m_api.np2api_main(app.argc, app.argv, this->m_np2widget->GetHandle());
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

#if defined(__WXMAC__) || defined(__WXGTK__)
    uint8_t keycode98 = KbdDrv::keycodeTransrate(event.GetRawKeyCode());
#elif defined(__WXMSW__)
    uint8_t keycode98 = KbdDrv::keycodeTransrate((event.GetRawKeyFlags() >> 16) & 0x1ff);
#endif
    printf("keycode98:%u, 0x%x\n", keycode98, keycode98);
    if(keycode98 == KEYCODE98_NC) {
        return;
    }
    m_api.np2api_keydown(keycode98);
}

void wxNP21kaiMFrame::OnShow( wxShowEvent& event )
{
}

void wxNP21kaiMFrame::OnKeyUp( wxKeyEvent& event )
{
#if defined(__WXMAC__) || defined(__WXGTK__)
    uint8_t keycode98 = KbdDrv::keycodeTransrate(event.GetRawKeyCode());
#elif defined(__WXMSW__)
    uint8_t keycode98 = KbdDrv::keycodeTransrate((event.GetRawKeyFlags() >> 16) & 0x1ff);
#endif
    if(keycode98 == KEYCODE98_NC) {
        return;
    }
    m_api.np2api_keyup(keycode98);
}

void wxNP21kaiMFrame::OnExit( wxCommandEvent& event )
{
    this->Close();
}
