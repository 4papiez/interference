///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDIALOG_H__
#define __GUIDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* draw_pane;
		wxStaticText* label_frequency;
		wxStaticText* label_amplitude;
		wxStaticText* label_wavelenght;
		wxStaticText* label_rotation;
		wxStaticText* label_angle;
		wxStaticText* label_color;
		wxSlider* frequency_slider;
		wxSlider* amplitude_slider;
		wxSlider* wavelenght_slider;
		wxSlider* rotation_slider;
		wxSlider* angle_slider;
		wxRadioButton* rbutton_gray;
		wxRadioButton* button_rb;
		wxRadioButton* rbutton_rgb;
		wxButton* button_reset;
		wxButton* button_save;
		wxTimer timer;
		
		// Virtual event handlers, overide them in your derived class
		virtual void draw_paneOnClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void draw_paneOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void button_resetOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_saveOnClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnTimerTimeout( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFKInterference"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~GUIDialog();
	
};

#endif //__GUIDIALOG_H__
