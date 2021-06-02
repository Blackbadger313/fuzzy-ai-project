#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include "D:\Github\AI\fuzzy-ai-project\src\fuzzyLogic.h"

using namespace std;

int main (){
    float kelembaban, suhu, keasaman, result;
    int sample;
    char terminator = 'y';

    cout << "\n\n\n\t\t\t\t=================================================================================================\n" 
    << "\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
    << "\t\t\t\t                    PROGRAM PENGUKURAN TINGKAT KESUBURAN TANAH OTOMATIS                          \n"
    << "\t\t\t\t                  PADA TANAMAN KOPI DENGAN METODE FUZZY INFERENSI MAMDANI                        \n"
    << "\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
    << "\t\t\t\t=================================================================================================\n"
    << endl;

    cout << "\t\t\t\t";
    system("pause");
    system("cls");

    while(terminator == 'Y' || terminator == 'y'){
        fuzzyLogic proses;
        cout << "\t\t\t\t=================================================================================================" << endl;
        cout << "\t\t\t\t========================================= Input Data ============================================" << endl;
        cout << "\t\t\t\t\t\t\t\t\tSuhu(C)       : "; cin >> suhu;
        cout << "\t\t\t\t\t\t\t\t\tKelembaban(%) : "; cin >> kelembaban;
        cout << "\t\t\t\t\t\t\t\t\tKeasaman(pH)  : "; cin >> keasaman;
        cout << "\t\t\t\t=================================================================================================" << endl;

        proses.derajatAnggotaSuhu(suhu);
        proses.derajatAnggotaKelembaban(kelembaban);
        proses.derajatAnggotaKeasaman(keasaman);

        cout << "\n\t\t\t\t=================================================================================================" << endl;
        cout << "\t\t\t\t====================================== Step 1 : Fuzifikasi ======================================" << endl;
        cout << "\t\t\t\t\t\t\t\t\tNilai Fuzzy Suhu" << endl;
        cout << "\t\t\t\t\t\t\t\t\tDingin : " << setprecision(2) << proses.termaSuhuDingin << endl;
        cout << "\t\t\t\t\t\t\t\t\tNormal : " << setprecision(2) << proses.termaSuhuNormal << endl;
        cout << "\t\t\t\t\t\t\t\t\tPanas  : " << setprecision(2) << proses.termaSuhuPanas << endl << endl;

        cout << "\t\t\t\t\t\t\t\t\tNilai Fuzzy Kelembapan" << endl;
        cout << "\t\t\t\t\t\t\t\t\tKering : " << setprecision(2) << proses.termaKelembabanKering << endl;
        cout << "\t\t\t\t\t\t\t\t\tLembab : " << setprecision(2) << proses.termaKelembabanLembab << endl;
        cout << "\t\t\t\t\t\t\t\t\tBasah  : " << setprecision(2) << proses.termaKelembabanBasah << endl << endl;

        cout << "\t\t\t\t\t\t\t\t\tNilai Fuzzy Keasaman" <<  endl;
        cout << "\t\t\t\t\t\t\t\t\tAsam   : " << setprecision(2) << proses.termaKeasamanAsam << endl;
        cout << "\t\t\t\t\t\t\t\t\tNetral : " << setprecision(2) << proses.termaKeasamanNetral << endl;
        cout << "\t\t\t\t\t\t\t\t\tBasa   : " << setprecision(2) << proses.termaKeasamanBasa << endl;
        cout << "\t\t\t\t=================================================================================================" << endl;

        cout << "\n\t\t\t\t=================================================================================================" << endl;
        cout << "\t\t\t\t====================================== Step 2 : Inferensi =======================================" << endl;
        proses.inferensi();

        if(proses.termaOutputKurangSubur > 0){
            cout << "\n\t\t\t\t\t\t\t\tNilai output terma kurang subur adalah " << proses.termaOutputKurangSubur << endl;
        }

        if(proses.termaOutputSubur > 0){
            cout << "\t\t\t\t\t\t\t\tNilai output terma subur adalah " << proses.termaOutputSubur;
        }
        cout << "\n\t\t\t\t=================================================================================================" << endl;

        cout << "\n\t\t\t\t=================================================================================================" << endl;
        cout << "\t\t\t\t====================================== Step 3 : Defuzzifikasi ===================================" << endl;
        cout << "\t\t\t\t\t\t\tMasukan banyak titik sampel yang di inginkan : "; cin >> sample;

        proses.defuzzifikasi(sample);

        cout << "\n\t\t\t\t\t\t\t\tNilai Pembilang       : " << to_string(proses.resultPembilang) << endl
        << "\t\t\t\t\t\t\t\tNilai Penyebut        : " << proses.resultPenyebut << endl
        << "\t\t\t\t\t\t\t\tNilai Kesuburan Tanah : " << proses.result;
        cout << "\n\n\t\t\t\t=================================================================================================" << endl << endl;

        cout << "\t\t\t\tMulai Pengukuran Kembali ?(Y/T) "; cin >> terminator;
        system("cls");
    }
    system("cls");

    cout << "\n\n\n\t\t\t\t=================================================================================================\n" 
    << "\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
    << "\t\t\t\t                                        TERIMAKASIH :)                                           \n"
    << "\t\t\t\t                                          SEE YOU..                                              \n"
    << "\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
    << "\t\t\t\t=================================================================================================\n"
    << endl;

}