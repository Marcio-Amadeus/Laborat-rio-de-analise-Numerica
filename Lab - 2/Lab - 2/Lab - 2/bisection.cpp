#include <stdio.h>
#include <math.h>

double bisection(double a, double b, int p, double(*f) (double x, void* data), void* data){


	double r, A_tent = a, B_temp = b;
	int n;
	double e;

	//calculo do erro
	n = 0;
	e = (double)fabs(B - A) / pow(2, n + 1);

	for (n = 1; erro > 0.5*pow(10, (-p)); n++){
		r = (a + b) / 2;
		e = (double)fabs(B - A) / pow(2, n + 1);
		printf("raiz:%.16g  iteração:%d\n", r, n);
		if (f(r, NULL)*f(a, NULL) < 0){
			b = r;
		}
		else a = r;

	}
	printf("raiz:%.16g  precisão: 0.5*10^(-%d)\n", r, p);
	return r;
}

double f(double x, void*data){
	double f;
	f = pow(x, 3) - x*sin(2 * x) + 0.2;
	return f;
}

int main(void){
	double a, b, p;
	double r;
	printf("Entre com o intervalo possível da raiz e a precisão:\n");
	scanf("%lf%lf%lf", &a, &b, &p);
	r = bisection(a, b, p, f, NULL);
	printf("raiz é %.16g \n", r);

	return 0;
}