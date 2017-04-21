#include<stdio.h>

#define _USE_MATH_DEFINES
#include<math.h>
#include<float.h>


double get_next(double x);
double func(double x);
double diff_func(double x);

int main() {
	double pre_x = M_PI;
	double x;
	int count=0;
	while (1)
	{
		x = get_next(pre_x);
		printf("x:%e, f(x):%e\n", x, func(pre_x));
		printf("diff:%e\n", fabs(pre_x - x));
		if (fabs(pre_x - x)<DBL_MIN || count > 2000)
		{
			break;
		}
		pre_x = x;
		count++;
	}
}

double get_next(double x) {
	double ans;
	ans = x - func(x) / diff_func(x);
	return ans;
}

double func(double x) {
	double ans;
	ans = -2 * sin(x) + exp(x + 1.0) + x - 10;
	return ans;
}

double diff_func(double x) {
	double ans;
	ans = -2 * cos(x) + exp(x + 1.0) + 1;
	return ans;
}