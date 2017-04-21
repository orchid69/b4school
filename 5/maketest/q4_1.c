#include<stdio.h>
#include<math.h>
#include<float.h>

double get_next(double x);
double func(double x);
double diff_func(double x);

int main() {
	double pre_x = 0;
	double x;
	while (1)
	{
		x = get_next(pre_x);
		printf("x:%e, f(x):%e\n", x, func(pre_x));
		printf("err:%e\n", fabs(pre_x - 0.63805));
		if (fabs(pre_x - x)<=DBL_MIN)
		{
			break;
		}
		pre_x = x;
	}
}

double get_next(double x) {
	double ans;
	ans = x - func(x) / diff_func(x);
	return ans;
}

double func(double x) {
	double ans;
	ans = -2 * pow(x, 4.0) + 3 * pow(x, 3.0) + 4 * x - 3;
	return ans;
}

double diff_func(double x) {
	double ans;
	ans = -8 * pow(x, 3.0) + 9 * pow(x, 2.0) + 4;
	return ans;
}