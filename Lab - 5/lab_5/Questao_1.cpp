#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* cos */
#include <cmath> 

#define PI 3.14159265
unsigned int fat(unsigned int n) {
	return n == 0 ? 1 : n * fat(n - 1);
}


int Chebyshev(int p, double**X, double**Y){

	int i = 0;
	int n = 0;
	int a = 0, b = PI / 2;

	//double test = cos(5);



	//Neste caso o erro é 1/fat porque o valor maximo do sin ou coss é sempre 1.
	double erro = (b - a) ^ n / (2 ^ (n - 1)) * 1 / fat(n);
	double precisao = 0.5*pow(10, -p);

	while (erro >= precisao){
		n++;
		erro = ((b - a) ^ n / (2 ^ (n - 1))) * 1 / fat(n);
	}
	//Bi = 2i-1
	X = (double**)malloc(n * sizeof(double*));
	Y = (double**)malloc(n * sizeof(double*));
	
	while (i<n){
		*X = (double*)malloc(sizeof(double));
		**X  = ((b - a) / 2)*cos((2 * i - 1)*PI / 2 * n) + (b + a) / 2;
		*Y = (double*)malloc(sizeof(double));
		**Y = cos(**X);

		**X++;
		**Y++;
		i++;
	}

	return i;
}



int main(void){



	int num = Chebyshev(6, NULL, NULL);
	printf("Numero de iteracoes: %d\n", num);
	system("pause");

}