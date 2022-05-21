#include "jobListBox.h"
#include <wx/textdlg.h>
#include "stringConstants.h"






/*
TODO:

    actually figure out how to make the list happen

*/



Listbox::Listbox(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200))
{

    wxPanel* panel = new wxPanel(this, -1);

    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    listbox = new wxListBox(panel, ID_LISTBOX,
        wxPoint(-1, -1), wxSize(-1, -1));

    joblistpanel = new jobListPanel(panel);

    wxFlexGridSizer* jobInfoRowsSizer = new wxFlexGridSizer(3, 1, 10, 0);
    //wxFlexGridSizer(int rows, int cols, int vgap, int hgap)

    wxStaticText* jobTitle = new wxStaticText(panel, -1, wxT("Project Manager"));
    wxStaticText* jobTraitsTitle = new wxStaticText(panel, -1, "Job Traits:");
    
    wxStaticText* jobTraits = new wxStaticText(panel, -1, jobTraitsString);
    jobTraits->Wrap(jobTraits->GetClientSize().GetWidth());
    wxStaticText* jobDesc = new wxStaticText(panel, -1, LOREM_IPSUM);
    jobDesc->Wrap(jobDesc->GetClientSize().GetWidth());



    wxFont jobTitleFont = jobTitle->GetFont();
    jobTitleFont.SetWeight(wxFONTWEIGHT_BOLD);
    jobTitle->SetFont(jobTitleFont);

    wxFont jobTraitsTitleFont = jobTraitsTitle->GetFont();
    jobTraitsTitleFont.SetUnderlined(true);
    jobTraitsTitle->SetFont(jobTraitsTitleFont);


    jobInfoRowsSizer->Add(jobTitle);
    jobInfoRowsSizer->Add(jobTraitsTitle);
    jobInfoRowsSizer->Add(jobTraits);
    jobInfoRowsSizer->Add(jobDesc, 1, wxEXPAND);
    


    hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
    
    hbox->Add(jobInfoRowsSizer, 3,  wxEXPAND | wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);


    panel->SetSizer(hbox);
    Center();
}


jobListPanel::jobListPanel(wxPanel* parent)
    : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    Listbox* lb = (Listbox*)parent->GetParent();
    m_lb = lb->listbox;


    m_lb->Append("blah");
    m_lb->Append("blah");
    m_lb->Append("blah");
    m_lb->Append("blah");
    m_lb->Append("blah");
    m_lb->Append("blah");

    //wxString lucia = "text";

    //wxArrayString* arrstrluc;
    //arrstrluc->Add(lucia);

    //m_lb->Append(wxT(lucia));
    //wxArrayString* arrstrluc = new wxArrayString{ "hi", "hello", "wow" };

    //m_lb->SetFirstItem(lucia);

    //m_lb->Append(wxT("abcdef"));

    //m_lb->InsertItems();

    //InsertItems (const wxArrayString &items, unsigned int pos)


    m_lb->Append("test");




    vbox->Add(-1, 20);

    SetSizer(vbox);
}
