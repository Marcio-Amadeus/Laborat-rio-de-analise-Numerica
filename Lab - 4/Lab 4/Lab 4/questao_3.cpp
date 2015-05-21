#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include "questao_1.h"
#include "questao_2.h"



// Questao 3
int main(void){
	int n = 3;

	double* M;
	double m[9] = { 1, 2, -3, 2, 1, 1, -1, -2, 1 };
	M = m;

	double* B;
	double b[3] = { 3, 3, -6 };
	B = b;

	double x[3] = { 0, 0, 0 };
	double *X;
	X = x;

	naiveGaussElimination(n, M, B);
	backSubstitution(n, M, B, X);
	system("pause");
	return 0;
}