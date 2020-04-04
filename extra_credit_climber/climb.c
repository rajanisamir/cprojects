#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "lib/climb.h"
#include "lib/hashtable.h"
#include "lib/legal_position.h"

int main(int argc, char** argv) {
    /* process input and store file pointers in fpSize and fpWall */
    if (argc != 3) {
        printf("ERROR: Incorrect number of arguments.\nUsage: ./climb size.txt wall.txt.\n");
        return 1;
    }
    FILE* fpSize = fopen(argv[1], "r");
    if (fpSize == NULL) {
        printf("ERROR: First file argument not found.\nUsage: ./climb size.txt wall.txt.\n");
        return 2;
    }
    FILE* fpWall = fopen(argv[2], "r");
    if (fpWall == NULL) {
        printf("ERROR: Second file argument not found.\nUsage: ./climb size.txt wall.txt.\n");
        return 3;
    }

    /* process fpSize and store sizes in A, T, and L */
    char nextLine[100];
    int A = atoi(fgets(nextLine, 100, fpSize));
    int T = atoi(fgets(nextLine, 100, fpSize));
    int L = atoi(fgets(nextLine, 100, fpSize));
    fclose(fpSize);

    /* process fpWall and store wall positions in holds, number of positions in n */
    int n = 0;
    while (!feof(fpWall)) {
        fgets(nextLine, 100, fpWall);
        n++;
    }
    fclose(fpWall);
    
    int** holds = malloc(n * sizeof(int*));
    fpWall = fopen(argv[2], "r");

    /* initialize hashtable */
    hashtable* visited = allocate(5000);

    /* TODO (non-essential): make it so that extra line at end of wall.txt doesn't cause segfault */
    node hold;
    for (int i = 0; i < n; i++) {
        fgets(nextLine, 100, fpWall);
        holds[i] = malloc(3 * sizeof(int));
        holds[i][0] = atoi(strtok(nextLine, " "));
        holds[i][1] = atoi(strtok(NULL, " "));
        /* add hold to hashtable */
        hold.x = holds[i][0];
        hold.y = holds[i][1];
        put(visited, hold, 0);
    }
    for (int i = 0; i < n; i++) {
        holds[i][2] = pow(holds[i][0] - holds[n-1][0], 2) + pow(holds[i][1] - holds[n-1][1], 2);
    }
    fclose(fpWall);
    
    /* initialize starting coordinates in coords */
    int coords[] = {holds[0][0], holds[0][1], holds[0][0], holds[0][1], holds[0][0], holds[0][1], holds[0][0], holds[0][1]};
    int start_x = holds[0][0];
    int start_y = holds[0][1];

    qsort((void*) holds, n, sizeof(int*), compare_holds);

    /* initialize limb queue in limb_queue */
    int limb_queue[] = {0, 1, 2, 3};

    /* initialize linked list of moves */
    move* moves = NULL;

    /* call make_move */
    int moved = make_move(A, T, L, &moves, moves, coords, limb_queue, holds, n, visited);

    /* print linked list */
    if (moved == 0) print_moves(moves, start_x, start_y);
    else printf("Terminated without finding a path.");

    /* free all allocated memory */
    free_moves(moves);
    for (int i = 0; i < n; i++) {
        free(holds[i]);
    }

    free(holds);

    deallocate(visited);

    return 0;
}

int compare_holds(const void* hold1, const void* hold2) {
    int* first = * (int**) hold1;
    int* second = * (int**) hold2;
    return first[2] - second[2];
}

void print_moves(move* moves, int start_x, int start_y) {
    while (moves->next != NULL) {
        moves = moves->next;
    }
    printf("RF %d %d\n", start_x, start_y);
    while (moves != NULL) {
        if (moves->limb == 0) printf("LH ");
        if (moves->limb == 1) printf("RH ");
        if (moves->limb == 2) printf("LF ");
        if (moves->limb == 3) printf("RF ");
        printf("%d ", moves->x);
        printf("%d\n", moves->y);
        moves = moves->prev;
    }
}

move* add_move(move* moves, int limb, int x, int y) {
    move* new_move = malloc(sizeof(move));
    new_move->limb = limb;
    new_move->x = x;
    new_move->y = y;
    new_move->next = moves;
    new_move->prev = NULL;
    if (moves != NULL) moves->prev = new_move;
    return new_move;
}

move* pop_move(move* head) {
    if (head == NULL) return NULL;
    else {
        move* next = head->next;
        free(head);
        return next;
    }
}

void free_moves(move* moves) {
    move* next;
    while (moves != NULL) {
        next = moves->next;
        free(moves);
        moves = next;
    }
}

void popToBack(int* arr, int n) {
    int toBack = arr[0];
    for (int i = 0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = toBack;
}

int make_move(int A, int T, int L, move** head, move* moves, int* coords, int* limb_queue, int** holds, int n, hashtable* visited) {
    /* create array for new coordinates and copy over current coordinates */
    int new_coords[8];
    for (int i = 0; i < 8; i++) {
        new_coords[i] = coords[i];
    }
    /* iterate through each of first three limbs in the queue */
    for (int i = 0; i < 3; i++) {
        int limb = limb_queue[0];
        popToBack(limb_queue, 4);
        /* iterate through each possible hold */
        for (int j = 0; j < n; j++) {
            new_coords[limb * 2] = holds[j][0];
            new_coords[limb * 2 + 1] = holds[j][1];
            node cur_hold;
            cur_hold.x = holds[j][0];
            cur_hold.y = holds[j][1];
            if (legal_position(A, T, L, new_coords) && !limb_visited(visited, cur_hold, limb)) {
                moves = add_move(moves, limb, holds[j][0], holds[j][1]);
                *head = moves;
                /* update hashtable */
                update(visited, cur_hold, limb);
                /* if we have reached the end position, return 0 */
                if (holds[j] == holds[0] && (limb == 0 || limb == 1)) {
                    return 0;
                }
                /* if we haven't reached the end yet, recurse */
                else {
                    int result = make_move(A, T, L, head, moves, new_coords, limb_queue, holds, n, visited);
                    if (result == 0) return 0;
                    else {
                        moves = pop_move(moves);
                        *head = moves;
                    }
                }
            }
        }
        new_coords[limb * 2] = coords[limb * 2];
        new_coords[limb * 2 + 1] = coords[limb * 2 + 1];
    }
    return -1;
}
