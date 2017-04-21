#include<stdio.h>

#define N 6

void mat_mlt(double mat1[N][N], double mat2[N][N], double ans[N][N]);
void mat_vec(double mat[N][N], double vec[], double ans[]);
void show_mat(double mat[N][N]);
void show_vec(double vec[]);
void ch_vec(double vec[]);

int main() {
	double s = 0.2;
	double mat[6][6];
	int i, j;
	/*
	double vec1[6] = {s+(1-s)/2,(1-s)/2,(1-s)/6,0,0,0}
	for(i=0;i<N;i++){
	for(j=0;j<N;j++){
	mat[i][j] = vec1[j];
	}
	ch_vec(vec1);
	}
	*/
	mat[0][0] = s + (1 - s) / 2;
	mat[0][1] = (1 - s) / 2;
	mat[0][2] = (1 - s) / 6;
	mat[0][3] = 0;
	mat[0][4] = 0;
	mat[0][5] = 0;
	mat[1][0] = (1 - s) / 3;
	mat[1][1] = s;
	mat[1][2] = (1 - s) / 3;
	mat[1][3] = (1 - s) / 6;
	mat[1][4] = 0;
	mat[1][5] = 0;
	mat[2][0] = (1 - s) / 6;
	mat[2][1] = (1 - s) / 3;
	mat[2][2] = s;
	mat[2][3] = (1 - s) / 3;
	mat[2][4] = (1 - s) / 6;
	mat[2][5] = 0;
	mat[3][0] = s + (1 - s) / 2;
	mat[3][1] = (1 - s) / 2;
	mat[3][2] = (1 - s) / 6;
	mat[3][3] = 0;
	mat[3][4] = 0;
	mat[3][5] = 0;




	mat_vec(mat1, vec, vec_ans);
	mat_mlt(mat1, mat2, ans);
	show_vec(vec_ans);
	show_mat(ans);
}

void mat_mlt(double mat1[N][N], double mat2[N][N], double ans[N][N]) {
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

void mat_vec(double mat[N][N], double vec[], double ans[]) {
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

void show_mat(double mat[N][N]) {
	int i, j;
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			printf("%.3f ", mat[i][j]);
		}
		printf("\n");
	}
}

void show_vec(double vec[]) {
	int i;
	for (i = 0; i<N; i++) {
		printf("%.3f ", vec[i]);
		printf("\n");
	}
}

void ch_vec(double vec[]) {
	int i;
	int temp = vec[0];
	for (i = 0; i<N; i++) {
		if (i != N - 1) {
			vec[i] = vec[i + 1];
		}
		else {
			vec[i] = temp;
		}
	}
}
