/***************************************************************
 * Name:      tests.cpp
 * Author:    Mateusz Papiez ()
 * Created:   2017-01-07
 * Copyright: Mateusz Papiez ()
 * License:
 **************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "cpptest.h"

#ifdef WIN32
// kod brany pod uwagê w przypadku
// wykrycia platformy systemu Windows
#include "..\waveGenerator.h"
#else
// kod, który zostanie u¿yty w przypadku braku zgodnoœci
// obecnego œrodowiska z platform¹ "WIN32"
#include "../waveGenerator.h"
#endif



double abs(double a){
    if (a<0) return -a;
    else return a;
}


using namespace std;

using namespace cpptest;

int main()
{
    {
        cout<<"Wave_Generator_Inicjalization_Test"<<endl;
        //flaga active powinna byc false ze wzglêdu na l=0
        WaveGenerator wg = WaveGenerator(0,0,0,0,0,0);
        assertEquals(false,wg.active);
        cout<<endl;
    }
    {
        cout<<"Wave_Generator_Inicjalization_Length_Not_0_Test"<<endl;
        //flaga powinna zostaæ aktywowana
        WaveGenerator wg = WaveGenerator(0,0,0,0,2.05,0);
        assert(wg.active);
        cout<<endl;
    }
    {
        cout<<"Get_Amplitude_Zero_Test"<<endl;
        //Wywo³anie zaburzenia o zerowej amplitudzie
        WaveGenerator wg = WaveGenerator(0,0,26.02,0,28.01,0);
        double expResult = 0;
        assertEquals(expResult, wg.getAmplitude());
        cout<<endl;

    }
    {
        cout<<"Get_Amplitude_Not_Zero_Test"<<endl;
        //odczytanie niezerowej amplitudy
        double expResult = 1.1;
        WaveGenerator wg = WaveGenerator(0,0,0,expResult,0,0);
        assertEquals(expResult, wg.getAmplitude());
        cout<<endl;
    }
    {
        cout<<"Get_Value_When_Zeros_Test"<<endl;
        //wywo³anie zaburzenia o zerowej amplitudzie i odczytanie wartosci w losowych punktach w losowym czasie
        int nr=10;
        srand( time( NULL ) );
        WaveGenerator wg = WaveGenerator(0,0,02.09,0,25.08,0);
        vector<double> expResult;
        for(int i=0;i<nr;i++)
            expResult.push_back(0);
        vector<double> result;
        for(int i=0;i<nr;i++)
            result.push_back(wg.value(rand()%300,rand()%300,rand()%1000));
        assertEquals(expResult,result);
        cout<<endl;
    }
    {
        cout<<"Get_Value_When_Time_Is_0_In_PP_Test"<<endl;
        //odczytanie wartosci w punkcie wywo³ania zaburzenia o ampl. zero
        double expResult = 0;
        WaveGenerator wg = WaveGenerator(150,150,10,100,10,0);
        assert(abs(expResult-wg.value(150,150,0))< 0.0001);
        cout<<endl;
    }
    {
        cout<<"Get_Value_When_Time_Is_0_WithShift_In_PP_Test"<<endl;
        //odczytanie wartosci w punkcie wywo³ania zaburzenia o ampl. ró¿nej od zero
        double expResult = 3.14159;
        double f = 10;
        WaveGenerator wg = WaveGenerator(150,150,f,expResult,100,0);
        assert(abs(expResult-wg.value(150,150,225))< 0.0001);
        cout<<endl;
    }
    {
        cout<<"Get_Value_In_PP_When_Freq_Is_Changed_Test"<<endl;
        //dwukrotne zmniejszenie czêstotliwoœci powinno zwiêkszyæ dwukrotnie opóŸnienie
        double expResult = 0205;
        double f = 10;
        WaveGenerator wg = WaveGenerator(150,150,f,expResult,100,0);
        double value1 = wg.value(150,150,225);
        f = 5;
        WaveGenerator wg2 = WaveGenerator(150,150,f,expResult,100,0);
        double value2 = wg2.value(150,150,450);
        assert( (abs(expResult-value1)< 0.0001) && (abs(expResult-value2)< 0.0001) );
        cout<<endl;
    }
    {
        cout<<"Get_Value_In_PP_When_Length_Is_Changed_Test"<<endl;
        //zmiana d³ugoœci fali nie powinna zmieniaæ odczytywanej wartoœæ w punkcie pocz¹tkowym
        double expResult = 2.92;
        double l = 100;
        WaveGenerator wg = WaveGenerator(150,150,10,expResult,l,0);
        double value1 = wg.value(150,150,225);
        l = 50;
        WaveGenerator wg2 = WaveGenerator(150,150,10,expResult,l,0);
        double value2 = wg2.value(150,150,225);
        assert( (abs(expResult-value1)< 0.0001) && (abs(expResult-value2)< 0.0001) );
        cout<<endl;
    }
    {
        cout<<"Get_Value_In_PP+lx_Test"<<endl;
        //odczytanie wartoœci w punktach odleg³ych o d³ugoœæ fali po osi OX
        double f = 10;
        double l = 7;
        WaveGenerator wg = WaveGenerator(150,150,f,10,l,0);
        //cout<<wg.value(150+l,150,100);
        assert(abs(wg.value(150,150,100)-wg.value(150+l,150,100))< 0.0001);
        cout<<endl;
    }
    {
        cout<<"Get_Value_In_PP+ly_Test"<<endl;
        //odczytanie wartoœci w punktach odleg³ych o d³ugoœæ fali po osi OY
        double f = 10;
        double l = 7;
        WaveGenerator wg = WaveGenerator(150,150,f,10,l,0);
        //cout<<wg.value(150,150+l,100);
        assert(abs(wg.value(150,150,100)-wg.value(150,150+l,100))< 0.0001);
        cout<<endl;
    }

    #ifdef WIN32
    cin.get();
    #endif
    return 0;
}
