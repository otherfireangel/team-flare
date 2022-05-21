#include "main.h"
#include "jobListBox.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Listbox* listbox = new Listbox(wxT("Career Focus Recommendation App - Presented by Team Flare"));
    listbox->Show(true);

    return true;
}