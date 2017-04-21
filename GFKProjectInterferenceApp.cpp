/***************************************************************
 * Name:      GFKProjectInterferenceApp.cpp
 * Purpose:   Code for Application Class
 * Author:    KamilPiastowicz (kamilpiastowicz@onet.pl)
 * Created:   2017-01-05
 * Copyright: KamilPiastowicz ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "GFKProjectInterferenceApp.h"
#include "GFKProjectInterferenceMain.h"

IMPLEMENT_APP(GFKProjectInterferenceApp);

bool GFKProjectInterferenceApp::OnInit()
{
    wxInitAllImageHandlers();
    GFKProjectInterferenceDialog* dlg = new GFKProjectInterferenceDialog(0L);

    dlg->Show();
    return true;
}
