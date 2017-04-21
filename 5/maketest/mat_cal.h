#ifndef _INCLUDE_
#define _INCLUDE_
#define N 3
//q1
void mat_mlt(double mat1[][N], double mat2[][N], double ans[][N]);
void mat_vec(double mat[][N], double vec[], double ans[]);
void show_mat(double mat[][N]);
void show_vec(double vec[]);
void input_mat(double mat[][N]);
void input_vec(double vec[]);
//q2
void mat_n_power(double mat[][N], double ans[][N], int n);
void mat_cp(double nmat[][N], double mat[][N]);
void vec_cp(double nvec[], double vec[]);

#endif
