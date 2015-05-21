#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lab-6.h"
#include "Gauss.h"


Spline* SplineCreate(int n, double* x, double* y){

	Spline* spline;
	double A[n - 1], B[n - 1], D[n - 1], M[n + 1][n + 2];
	double** m;
	double* c;
	int i, j;

	spline = (Spline*)malloc((n - 1)*sizeof(Spline));

	//Constru¡Ño da Matriz M que ser∑ utilizada para achar os Ci's.
	//O enderen¡amento da matriz vai de 1 at» n, e a ultima coluna corresponde as igualdades do sistema.
	for (i = 0; i <= n; i++){
		for (j = 0; j <= n + 1; j++){
			M[i][j] = 0;
		}
	}
	//construindo as igualdades do sistema
	for (i = 2; i<n; i++){
		M[i][n + 1] = 3 * (y[i] - y[i - 1]) / (x[i] - x[i - 1]) - 3 * (y[i - 1] - y[i - 2]) / (x[i - 1] - x[i - 2]);
	}

	//Construindo a matriz nxn para achar os Ci's
	M[1][1] = 1;
	M[n][n] = 1;
	for (i = 2, j = 1; i<n + 1; i++, j++){
		M[i][i - 1] = x[j] - x[j - 1];
		M[i][i] = 2 * (x[j] - x[j - 1]) + 2 * (x[i + 1] - x[i]);
		M[i][i + 1] = (x[i + 1] - x[i]);
	}
	//------------------------------------------------------------

	//Achando os Ci's
	m = M;
	c = gauss(m, n);

	//Achando Ai, Bi e Di
	for (i = 0; i<n - 1; i++){
		A[i] = y[i];
		B[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]) - (x[i + 1] - x[i]) / 3 * (2 * c[i] + c[i + 1]);
		D[i] = (c[i + 1] - c[i]) / 3 * (x[i + 1] - x[i]);
	}

	//Construindo os Splines
	spline->a = A;
	spline->b = B;
	spline->c = c;
	spline->d = D;
	spline->x = x;
	spline->y = y;
	spline->n = n;

	return spline;
}

double SplineEval(Spline* s, double x){

	double S[(s->n) - 1];
	int i;
	for (i = 0; i<s->n; i++){
		S[i] = s->a[i] + s->b[i] * (x - (s->x[i])) + s->c[i] * pow(x - (s->x[i]), 2) + s->d[i] * pow(x - (s->x[i]), 3);
		printf("S[i] = %lf", S[i]);
	}

	return S[i];
}

int main(void){
	int n = 8;
	Spline* spline;
	//Pontos de interpola¡ao
	double X[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	double Y[8] = { 1, 6, 3, 4, 2, 4, 7, 2 };

	double xi = 1.0;
	double* x;
	double* y;
	x = X;
	y = Y;
	spline = SplineCreate(n, x, y);
	SplineEval(spline, xi);

	return 0;
}