#include "hashing.h"

int chaveDivisao(int key, int m, int* r) {
    if(key < 0 || m < 0) return 0;

    *r = key % m;

    return 1;
}

int chaveMultiplicacao(int key, int m, float a, int* r) {
    if(key < 0 || m < 0 || a < 0) return 0;

    float value = key * a;
    value = value - (int) value;
    *r = (int) (m * value);

    return 1;
}
