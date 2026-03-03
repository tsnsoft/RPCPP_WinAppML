///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticText1 = new wxStaticText( this, wxID_ANY, _("Hello, user! I'm a C++ program with wxWidgets!"), wxDefaultPosition, wxDefaultSize, 0 );
	wxStaticText1->Wrap( -1 );
	wxStaticText1->SetMinSize( wxSize( 350,-1 ) );

	fgSizer1->Add( wxStaticText1, 0, wxALL, 5 );

	wxString m_choice1Choices[] = { _("en"), _("kk"), _("ru"), _("uz") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	fgSizer1->Add( m_choice1, 0, wxALL, 5 );

	m_button1 = new wxButton( this, wxID_ANY, _("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button1, 0, wxALL, 5 );


	this->SetSizer( fgSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );

}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Hello!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Thank you"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, _("ok"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button3, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );


	this->SetSizer( gSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyDialog1::~MyDialog1()
{
}

MyFrame2::MyFrame2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("good"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer2->Add( m_staticText5, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, _("C++ like"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer2->Add( m_staticText6, 0, wxALL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, _("Press me"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button5, 0, wxALL, 5 );


	this->SetSizer( gSizer2 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame2::~MyFrame2()
{
}
