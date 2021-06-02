#include <iostream>
using namespace std;
#define twopi 6.28
#define SampleRate 48000;


class Mixer { //mixa os sinais que são guardados nas variáveis ChannelA e ChannelB
public:

    float ChannelA = 0;
    float ChannelB = 0;
    float Mix = 0;

   static int SetandGetNewChannels() { //Determina e retorna o numero de canais

       int numChannels = 2;


        return numChannels;

    };

    float Mixar(float channelA, float channelB) { //Mixa os sinais e divide pelo número de canais, retorna a float Mix que contém os valores mixados

        ChannelA = channelA;
        ChannelB = channelB;

        Mix = (ChannelA + ChannelB) / Mixer::SetandGetNewChannels();

        return Mix;

    }

   

    void Osciloscopio () { //Cria o osciloscópio no console, os valores que estão entre -1 e 1 da variável output/Mix são representados com uma resolução de 20 pontos discretos


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



        else  if (output > 1)
            std::cout << "-------------------O" << std::endl; //clipa o sinal

        else  if (output < -1)
            std::cout << "O-------------------" << std::endl;





    };

};

class Oscilador { //cria a classe Oscilador, que é onde os cálculos das ondas senoidais são feitos

public:

    float phase = 0;
    float deltaPhase = 0;
    float freq = 0;
    float Osc = 0;

   


    void Oscilar(float freq, float gain, float DCoffset) { //cria uma instancia de calculo de oscilação

        deltaPhase = twopi * freq / SampleRate;

        phase += deltaPhase;

        gain = gain * Mixer::SetandGetNewChannels(); //faz com que o ganho unitário sempre seja 1

        Osc = (sin(phase) * gain) + DCoffset;


    };

};


int main()
{

    Oscilador osc1 = Oscilador(); //cria os objetos osc1 e osc2 a partir da classe Oscilador
    Oscilador osc2 = Oscilador();
    Mixer mixer = Mixer(); //cria um objeto mixer dentro da classe Mixer

    while (1) {

        osc1.Oscilar(2000, 0.5, 0); // frequencia, ganho
        osc2.Oscilar(100, 1, 0);

        mixer.Mixar(osc1.Osc, osc2.Osc); //recebe os parametros para serem mixados

      mixer.Osciloscopio(); //desenha o osciloscopio no console





    //Formas de onda:

      //--------------------------------------||
      //  Sine pura                           ||
      //                                      ||
      //         osc1.Oscilar(2000, 1, 0);    ||
      //______________________________________||
       
      //--------------------------------------||
      //  Quadrada "Analogica":               ||
      //                                      ||
      //         osc1.Oscilar(2000, 10, 0);   ||
      //______________________________________||

      //--------------------------------------||
      //  Modulação por Amplitude:            ||
      //                                      ||
      //         osc1.Oscilar(2000, 0.5, 0);  || 
      // osc2.Oscilar(100, 1, 0);             ||
      //______________________________________||




    }




}


