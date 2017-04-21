#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mat_cal.h"

// For q1 begin//
void mat_mlt(double mat1[][N], double mat2[][N], double ans[][N]) {
	int i, j, k;
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			ans[i][j] = 0;
			for (k = 0; k<N; k++) {
				ans[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void mat_vec(double mat[][N], double vec[], double ans[]) {
	int i, j, k;
	for (i = 0; i<N; i++) {
		for (j = 0; j<1; j++) {
			ans[i] = 0;
			for (k = 0; k<N; k++) {
				ans[i] += mat[i][k] * vec[k];
			}
		}
	}
}

void show_mat(double mat[][N]) {
	int i, j;
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			printf("%.3f ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void show_vec(double vec[]) {
	int i;
	for (i = 0; i<N; i++) {
		printf("%f ", vec[i]);
		printf("\n");
	}
	printf("\n");
}


void input_mat(double mat[][N]) {
	int i, j;
	while (1) {
		char yorn;
		printf("Input %d * %d Matrix.\n", N, N);
		for (i = 0; i<N; i++) {
			for (j = 0; j<N; j++) {
				scanf("%lf", &mat[i][j]);
			}
			printf("\n");
		}
		show_mat(mat);
		while (1) {
			printf("Is this OK? y or n:");
			int ret = scanf(" %c", &yorn);
			if (yorn == 'y') {
				break;
			}
			else if (yorn == 'n') {
				printf("Input again.\n");
				break;
			}
			else {
				while (getchar() != '\n') {} //バッファを捨てる
				printf("\n");
				continue;
			}
		}
		if (yorn == 'y') {
			break;
		}
		else if (yorn == 'n') {
			continue;
		}
	}
}

void input_vec(double vec[]) {
	int i;
	while (1) {
		char yorn;
		printf("Input %d dimension vector\n", N);
		for (i = 0; i<N; i++) {
			scanf("%lf", &vec[i]);
			printf("\n");
		}
		show_vec(vec);
		while (1) {
			printf("Is this OK? y or n:");
			int ret = scanf(" %c", &yorn);
			if (yorn == 'y') {
				break;
			}
			else if (yorn == 'n') {
				printf("Input again\n");
				break;
			}
			else {
				while (getchar() != '\n') {}
				printf("\n");
				continue;
			}
		}
		if (yorn == 'y') {
			break;
		}
		else if (yorn == 'n') {
			continue;
		}
	}
}
// For q1 end//

// For q2 start//
void mat_n_power(double mat[][N], double ans[][N], int n) {
	int i;
	double temp[N][N];
	mat_cp(temp, mat);
	for (i = 0; i < n; i++) {
		mat_mlt(temp, mat, ans);
		mat_cp(temp, ans);
	}
}

void mat_cp(double nmat[][N], double mat[][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
		{
			nmat[i][j] = mat[i][j];
		}
	}
}

void vec_cp(double nvec[], double vec[]) {
	int i;
	for (i = 0; i < N; i++) {
		nvec[i] = vec[i];
	}
}

// For q2 end //


