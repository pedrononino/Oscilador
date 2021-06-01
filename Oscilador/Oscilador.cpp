#include <iostream>
using namespace std;
#define twopi 6.28
#define SampleRate 48000;

class Oscilador {

public:

    float phase = 0;
    float deltaPhase = 0;
    float freq = 0;
    float Osc = 0;


    void Oscilar(float freq) {

        deltaPhase = twopi * freq / SampleRate;

        phase += deltaPhase;

        Osc = sin(phase);

            std::cout << Osc << std::endl;

    };

};

int main()
{

    Oscilador osc1 = Oscilador();


    while (1) {

        osc1.Oscilar(100.f);


    }




}


