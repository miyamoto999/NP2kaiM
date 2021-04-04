#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wxNP21kaiMApp.h"
#include "wxNP21kaiMFrame.h"

bool wxNP21kaiMApp::OnInit()
{
    locale.Init(wxLANGUAGE_DEFAULT);
    locale.AddCatalogLookupPathPrefix(_T("."));
    locale.AddCatalogLookupPathPrefix(_T("./locale/"));
    locale.AddCatalog(_T("wxNP21kaiM"));

    wxNP21kaiMFrame *frame = new wxNP21kaiMFrame(NULL);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(wxNP21kaiMApp);

