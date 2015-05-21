#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int iqi(double x0, double x1, double(*f)(double x), int p, double *r){
	double x2, x3;
	int i = 1;
	erro = //não soube avaliar o erro

		x2 = (x0 + x1) / 2;

	while (erro > 0.5*pow(10, -p)){
		fi = f(x2);
		fi1 = f(x1);
		fi2 = f(x0);
		x3 = fi1*fi / (fi2 - fi1)*(fi2 - fi)*x0 + fi2*fi / (fi1 - fi2)*(fi1 - fi)*x1 + fi2*fi1 / (fi - fi2)*(fi - fi1)*x2;
		x0 = x1;
		x1 = x2;
		x2 = x3;
		printf("xi+1 = %.16g na iteração: %d \n", x3, i);
		i++;
	}
	return i;

}

double f(double x){
	return exp(x) + sin(x) - 4;
}

int main(void){
	double x0;
	double x1;
	int p;
	printf("Entre a precisão:\n");
	scanf("%d", &p);

	for (i = 0, i<20, i++){
		x0 = -7, 5 + i*0.25;
		x1 = 5 - 0.15*i;
		printf("Valores iniciais x0 = %lf e x1 = %lf", x0, x1);
		iqi(x0, x1, f, p, NULL);
	}



}