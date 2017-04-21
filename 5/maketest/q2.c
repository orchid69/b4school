#include<stdio.h>
//#include<memory.h>
#include<math.h>
#include<float.h>
#include"mat_cal.h"

//!! MAKE SURE TO DEFINE "N" AS "6" IN "mat_cal.h"

int main() {
	double s = 0.2;
	double mat[6][6];
	double ans[6][6];
	double vec[6] = { 1,0,0,0,0,0 };
	double ansv[6];

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


	mat_n_power(mat, ans, 10);
	printf("10s\n");
	//show_mat(ans);
	mat_vec(ans, vec, ansv);
	show_vec(ansv);

	mat_n_power(mat, ans, 30);
	printf("20s\n");
	//show_mat(ans);
	mat_vec(ans, vec, ansv);
	show_vec(ansv);

	mat_n_power(mat, ans, 60);
	printf("60s\n");
	//show_mat(ans);
	mat_vec(ans, vec, ansv);
	show_vec(ansv);

	int flag = 0;
	int count = 0;
	double eps;
	while (flag < 6){
		mat_vec(mat, vec, ansv);
		int i;
		flag = 0;
		for (i = 0; i < 6; i++) {
			eps = fabs(ansv[i] - vec[i]);
			if (eps < DBL_MIN) {
				flag += 1;
			}
			else {
				
			}
		}
		vec_cp(vec, ansv);
		count++;
	}
	printf("Converged at %d s\n", count);
	printf("EPS is %e\n", DBL_MIN);
	show_vec(ansv);
}


