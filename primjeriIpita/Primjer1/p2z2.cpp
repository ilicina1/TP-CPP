#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 4 * atan(1);

class Ugao{
    double rad;
public:
    Ugao(double rad = 0) : rad(rad) { Postavi(rad); }
    Ugao(int stepeni, int minute, int sekunde) { Postavi(stepeni,minute,sekunde); }
    void Postavi(double rad){
        if(rad > 2*pi) this->rad = fmod(rad, 2*pi);
    }
    void Postavi(int stepeni, int minute, int sekunde){
        double decimalDegree = stepeni + minute/60 + sekunde/3600;
        rad = pi * (decimalDegree/180);
    }
    double DajRadijane() const { return rad; }
    int DajStepene() const { return rad * (180/pi); }
    int DajMinute() const { 
        double rez = fmod(rad * (180/pi), DajStepene());
        rez *= 60;
        return rez;
    }
    int DajSekunde() const { 
        double rez = fmod(rad * (180/pi), DajStepene());
        rez *= 60;
        double rez2 = fmod(rez, DajMinute());
        rez2 *= 60;
        return rez2;
    }
    
};

int main()
{
    Ugao a(1);
    std::cout << std::setprecision(2) << a.DajSekunde();
}
