#include "gcd.h"

#include <stdio.h>

int gcd(int x, int y) {
    int buffer;

    while (x > 0) {
        if (x < y) {
            buffer = x; x = y; y = buffer;
        }
        x %= y;
    }
    return y;
}
