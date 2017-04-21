#ifndef WAVEGENERATOR_H
#define WAVEGENERATOR_H

#include <math.h>

class WaveGenerator {
public:
    WaveGenerator(int x, int y, double f, double A, double l, double t0):
    _x(x), _y(y), _f(f), _t0(t0), _A(A), _l(l) {
        active = true;
        w = 2*M_PI*f;
        if (l<=0) {
            active = false;
            l = 1;
        }
        k = 2*M_PI/l;
        for(x = 0; x < 300; x++){
            for(y = 0; y < 300; y++){
                r[x][y] = sqrt((x-_x)*(x-_x) + (y-_y)*(y-_y));
            }
        }
    }

    double value(int x, int y, double t) {
        double dt = (t-_t0)/1000.0;
        if (r[x][y]/_f/_l < dt)
            return _A*sin(w*dt - k*r[x][y]);
        else
            return 0;
    }

    double getAmplitude() {
        return _A;
    }

    bool active;

private:
    int _x, _y;
    double _f, _A, _l; //czestotliwosc, amplituda, dlugosc fali
    long _t0;
    double w, k; // do optymalizacji

    double r[300][300]; //tablicujemy mozliwe odleglosci
};

#endif // WAVEGENERATOR_H
