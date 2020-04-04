#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lib/legal_position.h"

int main(int argc, char** argv) {
    /* process input and store file pointers in fpSize and fpWall */
    if (argc != 3) {
        printf("ERROR: Incorrect number of arguments.\nUsage: ./legal_position size.txt coordinates.txt.\n");
        return 1;
    }
    FILE* fpSize = fopen(argv[1], "r");
    if (fpSize == NULL) {
        printf("ERROR: First file argument not found.\nUsage: ./legal_position size.txt coordinates.txt.\n");
        return 2;
    }
    FILE* fpCoordinates = fopen(argv[2], "r");
    if (fpCoordinates == NULL) {
        printf("ERROR: Second file argument not found.\nUsage: ./legal_position size.txt coordinates.txt.\n");
        return 3;
    }

    /* process fpSize and store sizes in A, T, and L */
    char nextLine[100];
    int A = atoi(fgets(nextLine, 100, fpSize));
    int T = atoi(fgets(nextLine, 100, fpSize));
    int L = atoi(fgets(nextLine, 100, fpSize));
    fclose(fpSize);

    /* process fpCoordinates and store coordinates in coords */
    int coords[8];
    fgets(nextLine, 100, fpCoordinates);
    coords[0] = atoi(strtok(nextLine, " "));
    for (int i = 1; i < 8; i++) {
        coords[i] = atoi(strtok(NULL, " "));
    }
    fclose(fpCoordinates);

    /* check if the provided position is legal and print to output */
    printf("%d\n", legal_position(A, T, L, coords));
    return 0;
}
