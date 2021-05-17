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
