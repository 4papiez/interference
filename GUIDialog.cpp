///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIDialog.h"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* sizer_dc;
	sizer_dc = new wxFlexGridSizer( 1, 2, 0, 0 );
	sizer_dc->AddGrowableCol( 0 );
	sizer_dc->AddGrowableRow( 0 );
	sizer_dc->SetFlexibleDirection( wxBOTH );
	sizer_dc->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	draw_pane = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	draw_pane->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	draw_pane->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	sizer_dc->Add( draw_pane, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* sizer_c;
	sizer_c = new wxFlexGridSizer( 1, 2, 0, 0 );
	sizer_c->SetFlexibleDirection( wxHORIZONTAL );
	sizer_c->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* sizer_cl;
	sizer_cl = new wxBoxSizer( wxVERTICAL );
	
	label_frequency = new wxStaticText( this, wxID_ANY, wxT("Frequency"), wxDefaultPosition, wxSize( -1,30 ), 0|wxSIMPLE_BORDER );
	label_frequency->Wrap( -1 );
	sizer_cl->Add( label_frequency, 0, wxALL, 5 );
	
	label_amplitude = new wxStaticText( this, wxID_ANY, wxT("Amplitude"), wxDefaultPosition, wxSize( -1,30 ), 0|wxSIMPLE_BORDER );
	label_amplitude->Wrap( -1 );
	sizer_cl->Add( label_amplitude, 0, wxALL, 5 );
	
	label_wavelenght = new wxStaticText( this, wxID_ANY, wxT("WaveLenght"), wxDefaultPosition, wxSize( -1,30 ), 0|wxSIMPLE_BORDER );
	label_wavelenght->Wrap( -1 );
	sizer_cl->Add( label_wavelenght, 0, wxALL, 5 );
	
	label_rotation = new wxStaticText( this, wxID_ANY, wxT("Rotation"), wxDefaultPosition, wxSize( -1,30 ), 0|wxSIMPLE_BORDER );
	label_rotation->Wrap( -1 );
	sizer_cl->Add( label_rotation, 0, wxALL, 5 );
	
	label_angle = new wxStaticText( this, wxID_ANY, wxT("Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	label_angle->Wrap( -1 );
	sizer_cl->Add( label_angle, 0, wxALL|wxEXPAND, 5 );
	
	label_color = new wxStaticText( this, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	label_color->Wrap( -1 );
	sizer_cl->Add( label_color, 0, wxALL|wxEXPAND, 5 );
	
	
	sizer_c->Add( sizer_cl, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 8, 1, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	frequency_slider = new wxSlider( this, wxID_ANY, 10, 1, 100, wxDefaultPosition, wxSize( -1,30 ), wxSL_HORIZONTAL|wxRAISED_BORDER );
	fgSizer3->Add( frequency_slider, 0, wxALL|wxEXPAND, 5 );
	
	amplitude_slider = new wxSlider( this, wxID_ANY, 25, 1, 50, wxDefaultPosition, wxSize( -1,30 ), wxSL_HORIZONTAL|wxRAISED_BORDER );
	fgSizer3->Add( amplitude_slider, 0, wxALL|wxEXPAND, 5 );
	
	wavelenght_slider = new wxSlider( this, wxID_ANY, 50, 1, 100, wxDefaultPosition, wxSize( -1,30 ), wxSL_HORIZONTAL|wxRAISED_BORDER );
	fgSizer3->Add( wavelenght_slider, 0, wxALL|wxEXPAND, 5 );
	
	rotation_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 200,30 ), wxSL_HORIZONTAL );
	fgSizer3->Add( rotation_slider, 0, wxALL|wxEXPAND, 5 );
	
	angle_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer3->Add( angle_slider, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	rbutton_gray = new wxRadioButton( this, wxID_ANY, wxT("G-scale"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( rbutton_gray, 0, wxALL, 5 );
	
	button_rb = new wxRadioButton( this, wxID_ANY, wxT("RB"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( button_rb, 0, wxALL, 5 );
	
	rbutton_rgb = new wxRadioButton( this, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( rbutton_rgb, 0, wxALL, 5 );
	
	
	fgSizer3->Add( bSizer2, 1, wxEXPAND, 5 );
	
	button_reset = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( button_reset, 0, wxALL|wxEXPAND, 5 );
	
	button_save = new wxButton( this, wxID_ANY, wxT("Capture Image"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( button_save, 0, wxALL|wxEXPAND, 5 );
	
	
	sizer_c->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	
	sizer_dc->Add( sizer_c, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( sizer_dc );
	this->Layout();
	timer.SetOwner( this, wxID_ANY );
	
	// Connect Events
	draw_pane->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIDialog::draw_paneOnClick ), NULL, this );
	draw_pane->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIDialog::draw_paneOnPaint ), NULL, this );
	button_reset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::button_resetOnButtonClick ), NULL, this );
	button_save->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIDialog::button_saveOnClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::OnTimerTimeout ) );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	draw_pane->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIDialog::draw_paneOnClick ), NULL, this );
	draw_pane->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIDialog::draw_paneOnPaint ), NULL, this );
	button_reset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::button_resetOnButtonClick ), NULL, this );
	button_save->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIDialog::button_saveOnClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::OnTimerTimeout ) );
	
}
