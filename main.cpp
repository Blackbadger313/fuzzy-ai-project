#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "D:\Github\AI\fuzzy-ai-project\src\fuzzyLogic.h"

using namespace std;

int main (){
    float kelembaban, suhu, keasaman, result;
    int sample;
    fuzzyLogic proses;

    cout << "Input Data" << endl;
    cout << "Suhu(C) : "; cin >> suhu;
    cout << "Kelembaban(%) : "; cin >> kelembaban;
    cout << "Keasaman(pH) : "; cin >> keasaman;

    proses.derajatAnggotaSuhu(suhu);
    proses.derajatAnggotaKelembaban(kelembaban);
    proses.derajatAnggotaKeasaman(keasaman);

    cout << "\n===== Step 1 : Fuzifikasi =====" << endl;
    cout << "Nilai Fuzzy Suhu" << endl;
    cout << "Dingin : " << setprecision(2) << proses.termaSuhuDingin << endl;
    cout << "Normal : " << setprecision(2) << proses.termaSuhuNormal << endl;
    cout << "Panas : " << setprecision(2) << proses.termaSuhuPanas << endl << endl;

    cout << "Nilai Fuzzy Kelembapan" << endl;
    cout << "Kering : " << setprecision(2) << proses.termaKelembabanKering << endl;
    cout << "Lembab : " << setprecision(2) << proses.termaKelembabanLembab << endl;
    cout << "Basah : " << setprecision(2) << proses.termaKelembabanBasah << endl << endl;

    cout << "Nilai Fuzzy Keasaman" <<  endl;
    cout << "Asam : " << setprecision(2) << proses.termaKeasamanAsam << endl;
    cout << "Netral : " << setprecision(2) << proses.termaKeasamanNetral << endl;
    cout << "Basa : " << setprecision(2) << proses.termaKeasamanBasa << endl << endl;

    cout << "\n===== Step 2 : Inferensi =====" << endl;
    proses.inferensi();

    if(proses.termaOutputKurangSubur > 0){
        cout << "\nNilai output terma kurang subur adalah " << proses.termaOutputKurangSubur << endl;
    }

    if(proses.termaOutputSubur > 0){
        cout << "Nilai output terma subur adalah " << proses.termaOutputSubur << endl;
    }

    cout << "\n===== Step 3 : Defuzzifikasi =====" << endl;
    cout << "Masukan banyak titik sampel yang di inginkan : "; cin >> sample;

    proses.defuzzifikasi(sample);

    cout << "\nNilai Pembilang : " << to_string(proses.resultPembilang) << endl
    << "Nilai Penyebut : " << proses.resultPenyebut << endl
    << "Nilai Kesuburan Tanah : " << proses.result << endl;
}