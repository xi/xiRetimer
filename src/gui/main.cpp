#include "main.h"


IMPLEMENT_APP(wxWidgetsApp)

wxWidgetsApp::wxWidgetsApp()
{
}

wxWidgetsApp::~wxWidgetsApp()
{
}

bool wxWidgetsApp::OnInit()
{
    RetimerMainFrame* dialog = new RetimerMainFrame( (wxWindow*)NULL );
    dialog ->Show();
    SetTopWindow( dialog );
    return true;
}
