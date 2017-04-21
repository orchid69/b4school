#include <stdio.h>
#include "mat_cal2.h"

int main(){
	double a[N][N]={{1.0,0,0},{3.0,1.0,0},{-2.0,2.0,1.0}};
	double b[N] = {2.0,3.0,-1.0};
	int i,j,k;
	double d[N];
	double m[N][N];
	for(k=0;k<N-1;k++){
		d[k]=1/a[k][k];
		for(i=k+1;i<N;i++){
			m[i][k]=a[i][k]*d[k];
			for(j=k+1;j<N;j++){
				printf("%f-%f*%f",a[i][j],m[i][k],a[k][j]);
				a[i][j]=a[i][j]-m[i][k]*a[k][j];
				
				printf("a[%d][%d]:%f\n",i,j,a[i][j]);
			}
			b[i] = b[i] - m[i][k]*b[k];
		}
	}
	d[N-1] = 1/a[N-1][N-1];
	show_vec(b);
	show_mat(a);
}

//y_i=b_i-ƒ°(k=0~i-1) l_ik*y_k
