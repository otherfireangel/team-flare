#pragma once
#include <wx/wx.h>
#include <wx/listbox.h>

class jobListPanel : public wxPanel
{
public:
    jobListPanel(wxPanel* parent);

    wxListBox* m_lb;
    
};

class Listbox : public wxFrame
{
public:
    Listbox(const wxString& title);

    wxListBox* listbox;
    jobListPanel* joblistpanel;
    wxFlexGridSizer* jobInfoRowsSizer;
};

const int ID_RENAME = 1;
const int ID_LISTBOX = 5;