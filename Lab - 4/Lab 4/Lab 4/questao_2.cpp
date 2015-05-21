#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include "questao_1.h"
#include "questao_2.h"

///Questao 2
void backSubstitution(int n, double* A, double* b, double* x){

	int j, i, k;
	double f;
	/*double temp = 0;
	double temp2 = 0;
	double Prin[9];*/

	for (j = 2; j>1; j--){

		for (i = j + 1; i > 0; i--){



			for (k = j; k >= 0; k--){
				b[i] = b[i] - A[(i - 1)*n + k] * b[k];


			}
			b[i] = b[i] / A[(i - 1)*n + k];
			printf("b[%d] = %lf\n", (i - 1), b[k]);
		}
	}

}
