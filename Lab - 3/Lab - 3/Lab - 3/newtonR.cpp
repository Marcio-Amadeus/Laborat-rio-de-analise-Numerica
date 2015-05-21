#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int newtonR(double x0, double(*f) (double x), double(*fl) (double x), int p, double* r){

	double xi = x0;
	double dx;
	int j;

	dx = -f(xi) / fl(xi);

	for (j = 1; fabs(dx) > 0.5*pow(10, -p); j++)
	{

		dx = -f(xi) / fl(xi);
		xi += dx;

		printf("%.16g\n", dx);

		printf("Raiz encontrada em  %d iterações, r =  %.16g\n", j, xi);
	}

	return j;

}

double f(double x){
	double f;
	f = exp(pow(sin(x), 3)) + x*x*x*x*(x*x - 2 - 1 / x) - 1;
	return f;
}

double fl(double x){
	double fl;
	fl = 3 * sin(x)*sin(x)*cos(x)*exp(pow(sin(x), 3)) + x*x*x*(6 * x*x - 8 - 3 / x) - 1;
	return fl;
}

int main(void){
	int p;
	printf("Entre a precisão:\n");
	scanf("%d", &p);
	double init[3] = { 1, -2, 2 };
	int i;
	for (i = 0; i<3; i++){
		printf("Estimativa com o ponto inicial: %lf\n", init[i]);
		newtonR(init[i], f, fl, p, NULL);
	}


	return 0;
}
