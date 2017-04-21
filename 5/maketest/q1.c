#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "mat_cal.h"

int main() {
	int select;
	double mat1[N][N];
	double mat2[N][N];
	double ans[N][N];
	double vec[N];
	double vec_ans[N];
	while (1) {
		printf("Select matrix*matrix or matrix*vector.\n");
		printf("matrix*matrix -> 0 matrix*vector -> 1 :");
		scanf(" %d", &select);
		if (select == 0 || select == 1) {
			break;
		}
		else{
			while (getchar() != '\n') {} //バッファを捨てる
			printf("\n");
			continue;
		}
	}
	if (select == 0) {
		input_mat(mat1);
		input_mat(mat2);
		mat_mlt(mat1, mat2, ans);
		printf("mat1*mat2=\n");
		show_mat(ans);
	}
	else if (select == 1) {
		input_mat(mat1);
		input_vec(vec);
		mat_vec(mat1, vec, vec_ans);
		printf("mat*vec=\n");
		show_vec(vec_ans);
	}
	else{
		printf("error!");
	}
}
