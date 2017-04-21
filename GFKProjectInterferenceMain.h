/***************************************************************
 * Name:      GFKProjectInterferenceMain.h
 * Purpose:   Defines Application Frame
 * Author:    KamilPiastowicz (kamilpiastowicz@onet.pl)
 * Created:   2017-01-05
 * Copyright: KamilPiastowicz ()
 * License:
 **************************************************************/

#ifndef GFKPROJECTINTERFERENCEMAIN_H
#define GFKPROJECTINTERFERENCEMAIN_H

#include <wx/dcbuffer.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/image.h>
#include <wx/wfstream.h>
#include <vector>
#include "GFKProjectInterferenceApp.h"
#include "GUIDialog.h"
#include "vecmat.h"
#include "waveGenerator.h"

class GFKProjectInterferenceDialog: public GUIDialog
{
    public:
        GFKProjectInterferenceDialog(wxDialog *dlg);
        ~GFKProjectInterferenceDialog();
    private:
        virtual void draw_paneOnPaint( wxPaintEvent& event );
        virtual void button_resetOnButtonClick( wxCommandEvent& event );
		virtual void OnTimerTimeout( wxTimerEvent& event );
		virtual void draw_paneOnClick( wxMouseEvent& event );
		virtual void button_saveOnClick( wxMouseEvent& event );
		void drawMembrane(int beg, int increment, wxDC* dc);
		Matrix4 SetRotationMatrix();
		void generateFunction();
		void refresh();
		int valueToColor(double);
		double maxAmplitude();

		double funtab[300][300];
		double pointtab[300][300][2];
		//wxFileDialog save;
		std::vector<WaveGenerator> forcepoints;

};
#endif // GFKPROJECTINTERFERENCEMAIN_H
