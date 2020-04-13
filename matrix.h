#include <stdio.h>
#include <stdlib.h>

#include "../euclidean-algorithm/bezout.h"

#define p 13

typedef struct matrix *matrix;

extern matrix new_matrix(int n, int m);
extern void   print_matrix(matrix mat);

extern void update_mod(matrix mat, int mod);

// reduced row echelon form
extern void rref_mod(matrix mat, int mod);

// setters
extern void set_col(matrix mat, int c, int* col);

// setters
extern int* get_col(matrix mat, int c);
