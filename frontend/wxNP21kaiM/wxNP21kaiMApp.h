#ifndef __WXNP21KAIMAPP_H__
#define __WXNP21KAIMAPP_H__

class wxNP21kaiMApp:public wxApp
{
public:
    virtual bool OnInit();

private:
    wxLocale locale;
    void *m_dllcore;
};
wxDECLARE_APP(wxNP21kaiMApp);

#endif