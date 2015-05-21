#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include "questao_1.h"
#include "questao_2.h"

///M(i,j) por A(k) onde k = i*n + j 

// Questao 1
void naiveGaussElimination(int n, double* A, double* b){

	int j, i, k;
	double f;
	double temp = 0;
	double temp2 = 0;
	double Prin[9];

	for (j = 0; j<(n - 2); j++){

		for (i = j + 1; i <= n; i++){

			temp = A[(i - 1)*n + j];
			temp2 = A[j*n + j];
			f = temp / temp2;


			for (k = j; k <= (n - 1); k++){
				Prin[(i - 1)*n + k] = A[(i - 1)*n + k] - f*A[j*n + k];
				printf("A[%d] = %lf\n", (i - 1)*n + k, Prin[(i - 1)*n + k]);
			}
		}
	}

}


