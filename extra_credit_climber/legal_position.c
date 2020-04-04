#include <stdlib.h>
#include <math.h>
#include "lib/legal_position.h"

int legal_position(int A, int T, int L, int* coords) {
    int top[1000][1000];
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            if ((int) pow(coords[0] - x, 2) + (int) pow(coords[1] - y, 2) <= (int) pow(A, 2) &&
                (int) pow(coords[2] - x, 2) + (int) pow(coords[3] - y, 2) <= (int) pow(A, 2)) {
                    top[x][y] = 1;
                }
            else top[x][y] = 0;
        }
    }
    int bottom[1000][1000];
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            if ((int) pow(coords[4] - x, 2) + (int) pow(coords[5] - y, 2) <= (int) pow(L, 2) &&
                (int) pow(coords[6] - x, 2) + (int) pow(coords[7] - y, 2) <= (int) pow(L, 2)) {
                    bottom[x][y] = 1;
                }
            else bottom[x][y] = 0;
        }
    }
    for (int x = 0; x < 1000; x++) {
         for (int y = 0; y < 1000 - T; y++) {
             if ((top[x][y] == 1 && bottom[x][y+T] == 1) || (bottom[x][y] == 1 && top[x][y+T] == 1)) {
                 return 1;
             }
         }
    }
    return 0;
}
