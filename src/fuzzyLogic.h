#include <iostream>
#include "rumusFungsi.h"
#include <iomanip>

using namespace std;

class fuzzyLogic {
public:
    float termaSuhuDingin = 0, termaSuhuNormal = 0, termaSuhuPanas = 0;
    float termaKelembabanKering = 0, termaKelembabanLembab = 0, termaKelembabanBasah = 0;
    float termaKeasamanAsam = 0, termaKeasamanNetral = 0, termaKeasamanBasa = 0;
    float termaOutputSubur = 0, termaOutputKurangSubur = 0;
    float nilaiHasilRule[27];
    int tempCount = 0, rulesCount = 0;
    string kondisiHasilRule[27];

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

    void inferensi(){
        float derajatSuhu[3] = {
            termaSuhuDingin,
            termaSuhuNormal,
            termaSuhuPanas
        };
        float derajatKelembaban[3] = {
            termaKelembabanKering,
            termaKelembabanLembab,
            termaKelembabanBasah
        };
        float derajatKeasaman[3] = {
            termaKeasamanAsam,
            termaKeasamanNetral,
            termaKeasamanBasa
        };

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(derajatKelembaban[i] > 0 && derajatSuhu[j] > 0 && derajatKeasaman[k] > 0){
                        if(derajatKelembaban[i] <= derajatSuhu[j] && derajatKelembaban[i] <= derajatKeasaman[k]){
                            //kelembapan memiliki nilai min
                            nilaiHasilRule[tempCount] = derajatKelembaban[i];

                        }else if(derajatSuhu[j] <= derajatKelembaban[i] && derajatSuhu[j] <= derajatKeasaman[k]){
                            //suhu memiliki nilai min
                            nilaiHasilRule[tempCount] = derajatSuhu[j];

                        }else if(derajatKeasaman[k] <= derajatSuhu[j] && derajatKeasaman[k] <= derajatKelembaban[i]){
                            //keasaman memiliki nilai min
                            nilaiHasilRule[tempCount] = derajatKeasaman[k];

                        }

                        if(i == 0){
                            //termaKelembabanKering
                            if(j == 0){
                                //termaSuhuDingin
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }else if(j == 1){
                                //termaSuhuNormal
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }else if(j == 2){
                                //termaSuhuPanas
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }
                            }
                        }else if(i == 1){
                            //termaKelembabanLembab
                            if(j == 0){
                                //termaSuhuDingin
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }else if(j == 1){
                                //termaSuhuNormal
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }
                            }else if(j == 2){
                                //termaSuhuPanas
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }
                            }
                        }else if(i == 2){
                            //termaKelembabanBasah
                            if(j == 0){
                                //termaSuhuDingin
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }else if(j == 1){
                                //termaSuhuNormal
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }else if(j == 2){
                                //termaSuhuPanas
                                if(k == 0){
                                    //termaKeasamanAsam
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 1){
                                    //termaKeasamanNetral
                                    kondisiHasilRule[tempCount] = "KURANG SUBUR";
                                }else if(k == 2){
                                    //termaKeasamanBasa
                                    kondisiHasilRule[tempCount] = "SUBUR";
                                }
                            }
                        }

                        cout << rulesCount+1 <<".IF KELEMBABAN = " << derajatKelembaban[i]
                        << " AND SUHU = " << derajatSuhu[j]
                        << " AND KEASAMAN = " << derajatKeasaman[k]
                        << " THEN KESUBURAN = " << kondisiHasilRule[tempCount]
                        << "(" << nilaiHasilRule[tempCount] << ")" << endl;

                        tempCount ++;
                    }
                    rulesCount++;
                }
            }
        }

        for(int i = 0; i <= tempCount; i++){
            if(kondisiHasilRule[i] == "KURANG SUBUR"){
                //kurang subur memiliki nilai max
                if(i == 0){
                    termaOutputKurangSubur = nilaiHasilRule[i];
                }else if(nilaiHasilRule[i] > termaOutputKurangSubur){
                    termaOutputKurangSubur = nilaiHasilRule[i];
                }

            }else if(kondisiHasilRule[i] == "SUBUR"){
                //subur memiliki nilai max
                if(i == 0){
                    termaOutputSubur = nilaiHasilRule[i];
                }else if(nilaiHasilRule[i] > termaOutputSubur){
                    termaOutputSubur = nilaiHasilRule[i];
                }

            }
        }

        tempCount = 0;
    }
};