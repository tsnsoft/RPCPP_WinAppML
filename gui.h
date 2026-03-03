///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxStaticText* wxStaticText1;
		wxChoice* m_choice1;
		wxButton* m_button1;

		// Virtual event handlers, override them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Main Window"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 428,130 ), long style = wxCAPTION|wxCLOSE_BOX|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxButton* m_button3;

	public:

		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Dialog Window"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 200,100 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialog1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame2
///////////////////////////////////////////////////////////////////////////////
class MyFrame2 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxButton* m_button5;

	public:

		MyFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Second Window"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame2();

};

