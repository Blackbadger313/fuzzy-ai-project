using namespace std;
void segitigaKiri(float a, float b, float x, float *result){
    *result = (x - a) / (b - a);
}

void segitigaKanan(float b, float c, float x, float *result){
    *result = -1 * ((x - c) / (c - b));
}

void trapesiumKiri(float a, float b, float x, float *result){
    *result = (x - a) / (b - a);
}

void trapesiumKanan(float d, float c, float x, float *result){
    *result = (d - x) / (d - c);
}

void centroidMethodMamdani(int banyakSample, float pengaliSubur, float pengaliKurangSubur, float *hasilDefuzzifikasi, float *hasilPembilang, float *hasilPenyebut){
    float pengaliTengah[100] = {}, titikSampleTengah[100] = {};
    int sampleCountSubur = 0, sampleCountKurangSubur = 0, titikSample = 0, delta = 0;
    int tempCount = 0;

    delta = 100 / banyakSample;
    titikSample += delta;

    for(int i = 0; i < banyakSample; i++){
        if(titikSample <= 50){
            //termaOutputKurangSubur
            *hasilPembilang += titikSample * pengaliKurangSubur;
            sampleCountKurangSubur += 1;

        }else if(titikSample >= 60){
            //termaOutputSubur
            *hasilPembilang += titikSample * pengaliSubur;
            sampleCountSubur += 1;

        }else if(titikSample > 50 && titikSample < 60){
            //pengaliTengah
            if(pengaliKurangSubur > pengaliSubur){
                titikSampleTengah[tempCount] = titikSample;
                trapesiumKanan(60, 50, titikSampleTengah[tempCount], &pengaliTengah[tempCount]);
                *hasilPembilang += titikSampleTengah[tempCount] * pengaliTengah[tempCount];

            }else{
                titikSampleTengah[tempCount] = titikSample;
                trapesiumKiri(50, 60, titikSampleTengah[tempCount], &pengaliTengah[tempCount]);
                *hasilPembilang += titikSampleTengah[tempCount] * pengaliTengah[tempCount];

            }
            tempCount += 1;

        }
        titikSample += delta;

    }

    *hasilPenyebut = (sampleCountSubur * pengaliSubur) + (sampleCountKurangSubur * pengaliKurangSubur);
    for(int i = 0; i < tempCount; i++){
        *hasilPenyebut += pengaliTengah[i];
    }
    *hasilDefuzzifikasi = *hasilPembilang / *hasilPenyebut;
}