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

       // std::cout << Osc << std::endl;


    };

    void Draw() {

        if (Osc > -1 && Osc < -0.9)
            std::cout << "O-------------------" << std::endl;


        else  if (Osc > -0.9 && Osc < -0.8)
            std::cout << "-O------------------" << std::endl;

        else if (Osc > -0.8 && Osc < -0.7)
            std::cout << "--O-----------------" << std::endl;


        else  if (Osc > -0.7 && Osc < -0.6)
            std::cout << "---O----------------" << std::endl;


        else if (Osc > -0.6 && Osc < -0.5)
            std::cout << "----O---------------" << std::endl;


        else  if (Osc > -0.5 && Osc < -0.4)
            std::cout << "-----O--------------" << std::endl;

        else if (Osc > -0.4 && Osc < -0.3)
            std::cout << "------O-------------" << std::endl;


        else  if (Osc > -0.3 && Osc < -0.2)
            std::cout << "-------O------------" << std::endl;


        else if (Osc > -0.2 && Osc < -0.1)
            std::cout << "--------O-----------" << std::endl;


        else  if (Osc > -0.1 && Osc < 0)
            std::cout << "---------O----------" << std::endl;

        else if (Osc > 0 && Osc < 0.1)
            std::cout << "----------O---------" << std::endl;


        else  if (Osc > 0.1 && Osc < 0.2)
            std::cout << "-----------O--------" << std::endl;

        else  if (Osc > 0.2 && Osc < 0.3)
            std::cout << "------------O-------" << std::endl;

        else  if (Osc > 0.3 && Osc < 0.4)
            std::cout << "-------------O------" << std::endl;

        else  if (Osc > 0.4 && Osc < 0.5)
            std::cout << "--------------O-----" << std::endl;

        else  if (Osc > 0.5 && Osc < 0.6)
            std::cout << "---------------O----" << std::endl;

        else  if (Osc > 0.6 && Osc < 0.7)
            std::cout << "----------------O---" << std::endl;

        else  if (Osc > 0.7 && Osc < 0.8)
            std::cout << "-----------------O--" << std::endl;

        else  if (Osc > 0.8 && Osc < 0.9)
            std::cout << "------------------O-" << std::endl;

        else  if (Osc > 0.9 && Osc < 1)
            std::cout << "-------------------O" << std::endl;

      

    }

};

int main()
{

    Oscilador osc1 = Oscilador();


    while (1) {

        osc1.Oscilar(2000);

        osc1.Draw();



    }




}


