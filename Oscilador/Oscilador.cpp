#include <iostream>
using namespace std;
#define twopi 6.28
#define SampleRate 48000;


class Mixer {
public:

    int numChannels = 2;
    float ChannelA = 0;
    float ChannelB = 0;
    float Mix = 0;


    float Mixar(float channelA, float channelB) {

        ChannelA = channelA;
        ChannelB = channelB;

        Mix = (ChannelA + ChannelB) / numChannels;

        return Mix;

    }

    float getMix() {

        return Mix;
    }

    void Draw () {


        float output = Mix;



        if (output > -1 && output < -0.9)
            std::cout << "O-------------------" << std::endl;


        else  if (output > -0.9 && output < -0.8)
            std::cout << "-O------------------" << std::endl;

        else if (output > -0.8 && output < -0.7)
            std::cout << "--O-----------------" << std::endl;


        else  if (output > -0.7 && output < -0.6)
            std::cout << "---O----------------" << std::endl;


        else if (output > -0.6 && output < -0.5)
            std::cout << "----O---------------" << std::endl;


        else  if (output > -0.5 && output < -0.4)
            std::cout << "-----O--------------" << std::endl;

        else if (output > -0.4 && output < -0.3)
            std::cout << "------O-------------" << std::endl;


        else  if (output > -0.3 && output < -0.2)
            std::cout << "-------O------------" << std::endl;


        else if (output > -0.2 && output < -0.1)
            std::cout << "--------O-----------" << std::endl;


        else  if (output > -0.1 && output < 0)
            std::cout << "---------O----------" << std::endl;

        else if (output > 0 && output < 0.1)
            std::cout << "----------O---------" << std::endl;


        else  if (output > 0.1 && output < 0.2)
            std::cout << "-----------O--------" << std::endl;

        else  if (output > 0.2 && output < 0.3)
            std::cout << "------------O-------" << std::endl;

        else  if (output > 0.3 && output < 0.4)
            std::cout << "-------------O------" << std::endl;

        else  if (output > 0.4 && output < 0.5)
            std::cout << "--------------O-----" << std::endl;

        else  if (output > 0.5 && output < 0.6)
            std::cout << "---------------O----" << std::endl;

        else  if (output > 0.6 && output < 0.7)
            std::cout << "----------------O---" << std::endl;

        else  if (output > 0.7 && output < 0.8)
            std::cout << "-----------------O--" << std::endl;

        else  if (output > 0.8 && output < 0.9)
            std::cout << "------------------O-" << std::endl;

        else  if (output > 0.9 && output < 1)
            std::cout << "-------------------O" << std::endl;





    };

};

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

   

    float getOsc() {

        return Osc;

    }



    

};



int main()
{

    Oscilador osc1 = Oscilador();
    Oscilador osc2 = Oscilador();
    Mixer mixer = Mixer();

    while (1) {

        osc1.Oscilar(6000); // frequencia
        osc2.Oscilar(100);


       

        mixer.Mixar(osc1.Osc, osc2.Osc);

      mixer.Draw(); //desenha no console









    }




}


