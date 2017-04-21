#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<float.h>
#include"mat_cal.h"

void init_mat(double mat[N][N], double s);
void init_vec(double vec[N]);

int main() {
	double s[4] = { 0.0,0.2,0.5,0.8 };
	double mat[6][6];
	double ans[6][6];
	double vec[6] = { 1,0,0,0,0,0 };
	double ansv[6];
	int i;

	FILE *fp;
	char *fname = "q3_n.csv";
	char *s1 = "test01";
	int n1 = 10;
	fp = fopen(fname, "w");
	if (fp == NULL)
	{
		printf("%sERROR\n", fname);
		return -1;
	}
	int count;
	for (count = 0; count < 4; count++)
	{
		init_mat(mat, s[count]);
		init_vec(vec);
		for (i = 0; i < 30; i++)
		{
			mat_vec(mat, vec, ansv);
			int  k;
			fprintf(fp, "%d,", i+1);
			for (k = 0; k<N; k++) {
				fprintf(fp, "%f,", ansv[k]);
			}
			fprintf(fp, "\n");
			vec_cp(vec, ansv);
		}
		fprintf(fp, "\n");

		//get converged t
		int flag = 0;
		int cnt = 0;
		double eps;
		init_vec(vec);
		while (flag != 1) {
			mat_vec(mat, vec, ansv);
			flag = 0;
			eps = fabs(ansv[1] - vec[1]);
			if (eps < DBL_MIN) {
				flag = 1;
			}
			vec_cp(vec, ansv);
			cnt++;
		}
		fprintf(fp,"s=%f,p1 was converged at ,%d\n", s[count], cnt);
		fprintf(fp,"EPS is %e\n", DBL_MIN);
		int k;
		for (k = 0; k<N; k++) {
			fprintf(fp, "%f,", ansv[k]);
		}
		fprintf(fp, "\n\n");
		//show_vec(ansv);
	}

	fclose(fp);

	printf("%s DONE\n", fname);
	return 0;
}

void init_mat(double mat[N][N], double s) {
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
	mat[3][0] = 0;
	mat[3][1] = (1 - s) / 6;
	mat[3][2] = (1 - s) / 3;
	mat[3][3] = s;
	mat[3][4] = (1 - s) / 3;
	mat[3][5] = (1 - s) / 6;
	mat[4][0] = 0;
	mat[4][1] = 0;
	mat[4][2] = (1 - s) / 6;
	mat[4][3] = (1 - s) / 3;
	mat[4][4] = s;
	mat[4][5] = (1 - s) / 3;
	mat[5][0] = 0;
	mat[5][1] = 0;
	mat[5][2] = 0;
	mat[5][3] = (1 - s) / 6;
	mat[5][4] = (1 - s) / 2;
	mat[5][5] = s + (1 - s) / 2;

}

void init_vec(double vec[N]) {
	vec[0] = 1.0;
	vec[1] = 0;
	vec[2] = 0;
	vec[3] = 0;
	vec[4] = 0;
	vec[5] = 0;
}
