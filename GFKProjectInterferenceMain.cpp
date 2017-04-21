/***************************************************************
 * Name:      GFKProjectInterferenceMain.cpp
 * Purpose:   Code for Application Frame
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

#include "GFKProjectInterferenceMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



GFKProjectInterferenceDialog::GFKProjectInterferenceDialog(wxDialog *dlg): GUIDialog(dlg) {draw_pane->SetBackgroundStyle(wxBG_STYLE_PAINT);timer.Start(5);}

GFKProjectInterferenceDialog::~GFKProjectInterferenceDialog()
{
}
void GFKProjectInterferenceDialog::generateFunction(){
    double t = wxGetLocalTimeMillis().ToDouble();
    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 300; j++){
            funtab[i][j]=0;
            for(std::vector<WaveGenerator>::iterator it = forcepoints.begin(); it != forcepoints.end(); ++it) {
                funtab[i][j] += it->value(i, j, t);
            }
        }

    }
}
void GFKProjectInterferenceDialog::draw_paneOnPaint( wxPaintEvent& event ) { refresh(); }
void GFKProjectInterferenceDialog::button_resetOnButtonClick( wxCommandEvent& event ) { forcepoints.clear(); }
void GFKProjectInterferenceDialog::OnTimerTimeout( wxTimerEvent& event ) { draw_pane->Refresh();}
void GFKProjectInterferenceDialog::draw_paneOnClick( wxMouseEvent& event ) {
    int i,j;
    int x = event.GetPosition().x;
    int y = event.GetPosition().y;
    for(i = 0; i < 300; i++){
      for(j = 0; j < 300; j++){
        if(abs(pointtab[i][j][0]-x)==0 && abs(pointtab[i][j][1]-y)==0) break;
      }
      if(abs(pointtab[i][j][0]-x)==0 && abs(pointtab[i][j][1]-y)==0) break;
    }
    if(i!=300 && j!=300){
     double t = wxGetLocalTimeMillis().ToDouble();
     forcepoints.push_back(WaveGenerator(i,j,frequency_slider->GetValue()/10.0,amplitude_slider->GetValue(),wavelenght_slider->GetValue(),t));
    }
}
void GFKProjectInterferenceDialog::button_saveOnClick( wxMouseEvent& event ) {
      wxFileDialog *save = new wxFileDialog(this,wxT("Save file"),wxT(""),wxT(""),wxT("*.tiff"),wxFD_SAVE);
      wxMemoryDC mdc;
      wxClientDC dc(draw_pane);
      wxBitmap bmp(dc.GetSize().GetWidth(),dc.GetSize().GetHeight());

      timer.Stop();

      save->ShowModal();
      std::string dir = save->GetDirectory().ToStdString() + "/" + save->GetFilename().ToStdString()+".tiff";//tiff u mnie działało
      wxFileOutputStream fos(dir);

      int rot = rotation_slider->GetValue();
      if(rot < 50 || rot > 99){
        drawMembrane(299,-1, &dc);
      }else{
        drawMembrane(0,1, &dc);
      }

      mdc.SelectObject(bmp);

      mdc.Blit(0,0,dc.GetSize().GetWidth(),dc.GetSize().GetHeight(),&dc,0,0,wxCOPY,false,-1,-1   );

      wxImage im = bmp.ConvertToImage();
      im.SaveFile(dir,wxBITMAP_TYPE_TIFF);

      timer.Start(5);
}

inline Matrix4 GFKProjectInterferenceDialog::SetRotationMatrix(){
    Matrix4 mx, my, mz;
    double rx = (angle_slider->GetValue()*M_PI/200);
    double ry = (0*M_PI/180);
    double rz = (rotation_slider->GetValue()*M_PI/50);
    mx.data[0][0] = 1;
    mx.data[1][1] = cos(rx);
    mx.data[2][2] = cos(rx);
    mx.data[1][2] = -sin(rx);
    mx.data[2][1] = sin(rx);

    my.data[0][0] = cos(ry);
    my.data[2][2] = cos(ry);
    my.data[2][0] = sin(ry);
    my.data[0][2] = -sin(ry);
    my.data[1][1] = 1;

    mz.data[0][0] = cos(rz);
    mz.data[1][1] = cos(rz);
    mz.data[1][0] = sin(rz);
    mz.data[0][1] = -sin(rz);
    mz.data[2][2] = 1;

    return mx*my*mz;
}

void GFKProjectInterferenceDialog::refresh() {
    int rot = rotation_slider->GetValue();
    wxAutoBufferedPaintDC dc(draw_pane);
    if(rot < 50 || rot > 99){
        drawMembrane(299,-1, &dc);
    }else{
        drawMembrane(0,1, &dc);
    }
}

inline void GFKProjectInterferenceDialog::drawMembrane(int beg, int increment, wxDC* dc){
    dc->Clear();
    Vector4 point;
    Matrix4 transformation;
    wxPen pen;
    int w,h, color;

    generateFunction();
    draw_pane->GetSize(&w,&h);
    w /= 2; //optymalizacja
    h /= 2; //optymalizacja
    pen.SetWidth(3);

    transformation = SetRotationMatrix();
    double maxValue = maxAmplitude();

    int k=0;
    int m;
    for(int i = beg; k<300; i+=increment, k++){
        for(int j = beg, m=0; m<300; j+=increment, m++){
            point.Set(150-i,150-j,funtab[i][j]);
            point = transformation*point;

            // color = valueToColor(funtab[i][j]);
            color = (funtab[i][j]/maxValue + 1.0)*122.5; //optymalizacja
            if (rbutton_gray->GetValue()) {
                pen.SetColour(wxColour(color,color,color));
            } else if (button_rb->GetValue()) {
                pen.SetColour(wxColour(color,0,255-color));
            } else {
                color++;
                if (color<=128)
                    pen.SetColour(wxColour(255-(color*2-1),color*2-1,0));
                else {
                    color -= 128;
                    pen.SetColour(wxColour(0,255-(color*2-1),color*2-1));
                }
            }
            dc->SetPen(pen);

            dc->DrawPoint(point.data[0] + w, point.data[1] + h);
            pointtab[i][j][0]=point.data[0] + w;
            pointtab[i][j][1]=point.data[1] + h;
        }
    }
}

inline int GFKProjectInterferenceDialog::valueToColor(double value) { //actually not used
    return (value/maxAmplitude() + 1.0)*122.5;
}

inline double GFKProjectInterferenceDialog::maxAmplitude() {
    double ret = 0.0;
    for(std::vector<WaveGenerator>::iterator it = forcepoints.begin(); it != forcepoints.end(); ++it) {
        ret += it->getAmplitude();
    }
    return ret;
}
