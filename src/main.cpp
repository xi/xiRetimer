#include "gui/xiRTMainFrame.h"
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
    xiRTMainFrame* dialog = new xiRTMainFrame( (wxWindow*)NULL );
    dialog ->Show();
    SetTopWindow( dialog );
    return true;
}