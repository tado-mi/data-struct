#include "../matrix.h"

struct matrix {
  int** data;
  int n, m; // row, column
};

matrix new_matrix(int n, int m) {

  matrix mat = malloc(sizeof(struct matrix));
  (*mat).n = n;
  (*mat).m = m;
  (*mat).data = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i = i + 1) {
    (*mat).data[i] = malloc(m * sizeof(int));
    for (int j = 0; j < m; j = j + 1) {
      (*mat).data[i][j] = 0;
    }
  }
  return mat;

}

void print_matrix(matrix mat) {

  printf("%d x %d\n", (*mat).n, (*mat).m);
  for (int i = 0; i < (*mat).n; i = i + 1) {
    for (int j = 0; j < (*mat).m; j = j + 1) {
      printf("%d\t", (*mat).data[i][j]);
    }
    printf("\n");
  }

}

void update_mod(matrix mat, int mod) {

  for (int i = 0; i < (*mat).n; i = i + 1) {
    for (int j = 0; j < (*mat).m; j = j + 1) {
      int focus = (*mat).data[i][j] % mod;
      while (focus < 0) focus = focus + mod;
      (*mat).data[i][j] = focus;
    }
  }

}

// getters
int* get_col(matrix mat, int c) {

  int* ans = malloc((*mat).n * sizeof(int));
  for (int i = 0; i < (*mat).n; i = i + 1) {
    *(ans + i) = (*mat).data[i][c];
  }
  return ans;

}

// setters
void set_col(matrix mat, int c, int* col) {

  for (int i = 0; i < (*mat).n; i = i + 1) {
    (*mat).data[i][c] = col[i];
  }

}

void mult_row(matrix mat, int r, int scalar) {

}

// computes the reduced row echelon form
void rref_mod(matrix mat, int mod) {

  for (int i = 0; i < (*mat).n; i = i + 1) {

    int tmp = (*mat).data[i][i];
    if (tmp == 0) { // no inverse possible
      continue;
    }

    int focus = inverse(tmp, mod);
    mult_row(mat, i, focus);



  }

}

/*

matrix iden(int dim){

	matrix I = new_matrix(dim, dim);

	double** temp = malloc(dim * sizeof(double*));
	for (int i = 0; i < dim; i++) {

		*(temp + i) = malloc(dim * sizeof(double));
		for (int j = 0; j < dim; j++) temp[i][j] = (double) (i == j);

	}

	(*I).data = temp;
	return I;

}

matrix merge_col(matrix A, matrix B){

	if ((*A).r != (*B).r) return NULL;

	matrix ans = new_matrix((*A).r, (*A).c + (*B).c);

	double** temp = malloc((*ans).r * sizeof(double*));
	for (int i = 0; i < (*ans).r; i++) *(temp + i) = malloc((*ans).c * sizeof(double));
	malloc(1);

	for (int i = 0; i < (*ans).r; i++) {

		for (int j = 0; j < (*A).c; j++) temp[i][j] = (*A).data[i][j];
		for (int j = 0; j < (*ans).c - (*A).c; j++) temp[i][j + (*A).c] = (*B).data[i][j];

	}

	(*ans).data = temp;

	return ans;

}

matrix merge_row(matrix C, matrix D){

	if ((*C).c != (*D).c) return NULL;

	matrix ans = new_matrix((*C).r + (*D).r, (*C).c);


	double** temp = malloc((*ans).r * sizeof(double*));
	for (int i = 0; i < (*ans).r; i++) *(temp + i) = malloc((*ans).c * sizeof(double));
	malloc(1);

	for (int j = 0; j < (*ans).c; j++) {

		for (int i = 0; i < (*C).r; i++) temp[i][j] = (*C).data[i][j];
		for (int i = 0; i < (*ans).r - (*C).r; i++) temp[i + (*C).r][j] = (*D).data[i][j];

	}

	(*ans).data = temp;

	return ans;

}

matrix rref(matrix M){

	matrix X = new_matrix((*M).r, (*M).c);
	for (int i = 0; i < (*X).r; i++) for (int j = 0; j < (*X).c; j++) (*X).data[i][j] = (*M).data[i][j];

	int dim = (*X).r;
	if ((*X).r > (*X).c) dim = (*X).c;

	for (int k = 0; k < dim; k++) {

		if ((*X).data[k][k] == 0) {

//			find the row to swap kth row with
			int to_swap = k + 1;
			if (to_swap == (*X).r) break;
			while (to_swap < (*X).r && (*X).data[to_swap][k] == 0) to_swap = to_swap + 1;

//			swap kth row with to_swapth row
			for (int t = 0; t < (*X).c; t++){

				double temp = (*X).data[k][t];
				(*X).data[k][t] = (*X).data[to_swap][t];
				(*X).data[to_swap][t] = temp;

			}

		}

		double focus = (*X).data[k][k];

//		working with kth row
		for (int j = 0; j < (*X).c; j++) (*X).data[k][j] = (*X).data[k][j] / focus;
//		working with kth column
		for (int i = 0; i < (*X).r; i++) {

			if (i == k) continue;
			double coeff = - (*X).data[i][k];

			for (int t = 0; t < (*X).c; t++) {

				(*X).data[i][t] = (*X).data[i][t] + coeff * (*X).data[k][t];

			}

		}

		(*X).rank = k + 1;

	}

    (*M).rank = (*X).rank;
    return X;

}


}

*/



// testing main method
// int main() {
//
// }
