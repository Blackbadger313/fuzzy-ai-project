#include <iostream>
#include "rumusFungsi.h"
#include <iomanip>

using namespace std;

class fuzzyLogic {
public:
    float termaSuhuDingin = 0, termaSuhuNormal = 0, termaSuhuPanas = 0;
    float termaKelembabanKering = 0, termaKelembabanLembab = 0, termaKelembabanBasah = 0;
    float termaKeasamanAsam = 0, termaKeasamanNetral = 0, termaKeasamanBasa = 0;

public:
    void derajatAnggotaSuhu(float inputSuhu){
        if(inputSuhu <=10){
            //Dingin
            termaSuhuDingin = 1;

        }else if(inputSuhu == 20){
            //Normal
            termaSuhuNormal = 1;

        }else if(inputSuhu >= 40){
            //Panas
            termaSuhuPanas = 1;

        }else if(inputSuhu > 20 && inputSuhu < 40){
            //termaPanas
            trapesiumKiri(20, 40, inputSuhu, &termaSuhuPanas);

            //termaNormal
            segitigaKanan(20, 40, inputSuhu, &termaSuhuNormal);

        }else if(inputSuhu > 10 && inputSuhu < 20){
            //termaDingin
            trapesiumKanan(20, 10, inputSuhu, &termaSuhuDingin);
            
            //termaNormal
            segitigaKiri(10, 20, inputSuhu, &termaSuhuNormal);
        }
    }

    void derajatAnggotaKelembaban(float inputKelembaban){
        if(inputKelembaban <=30){
            //Kering
            termaKelembabanKering = 1;

        }else if(inputKelembaban == 50){
            //Lembab
            termaKelembabanLembab = 1;

        }else if(inputKelembaban >= 80){
            //Basah
            termaKelembabanBasah = 1;

        }else if(inputKelembaban > 50 && inputKelembaban < 80){
            //termaLembab
            segitigaKanan(50, 80, inputKelembaban, &termaKelembabanLembab);

            //termaBasah
            trapesiumKiri(50, 80, inputKelembaban, &termaKelembabanBasah);

        }else if(inputKelembaban > 30 && inputKelembaban < 50){
            //termaKering
            trapesiumKanan(50, 30, inputKelembaban, &termaKelembabanKering);

            //termaLembab
            segitigaKiri(30, 50, inputKelembaban, &termaKelembabanLembab);
        }
    }

    void derajatAnggotaKeasaman(float inputKeasaman){
        if(inputKeasaman <=4.5){
            //Asam
            termaKeasamanAsam = 1;

        }else if(inputKeasaman == 6){
            //Netral
            termaKeasamanNetral = 1;

        }else if(inputKeasaman >= 7.5){
            //Basa
            termaKeasamanBasa = 1;

        }else if(inputKeasaman > 6 && inputKeasaman < 7.5){
            //termaNetral
            segitigaKanan(6, 7.5, inputKeasaman, &termaKeasamanNetral);

            //termaBasa
            trapesiumKiri(6, 7.5, inputKeasaman, &termaKeasamanBasa);

        }else if(inputKeasaman > 4.5 && inputKeasaman < 6){
            //termaAsam
            trapesiumKanan(6, 4.5, inputKeasaman, &termaKeasamanAsam);

            //termaNetral
            segitigaKiri(4.5, 6, inputKeasaman, &termaKeasamanNetral);
        }
    }
};