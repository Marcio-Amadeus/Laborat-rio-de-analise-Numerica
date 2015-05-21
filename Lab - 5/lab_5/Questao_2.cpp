#include "Questao_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* cos */
#include <cmath> 


double lagrange(int n, double *X, double *Y, double x){



	float numerator;
	float denominator; 
	int i = 0;
	int j = 0;
	float y = 0;



	for (i = 0; i <= n; i++)
	{
		numerator = 1;
		denominator = 1;
		for (j = 0; j <= n; j++){
			if (j != i)
			{
				numerator *= x - X[j];
				denominator *= X[i] - X[j];
			}
			y += (numerator / denominator)*Y[i];
			
		}
		printf("Quando x=%4.1f y=%7.1f\n", x, y);
		return y;

		
	}

}

double myCos1(int n, double *X, double *Y, double x){

	int n = 4;
	double X[3] = { 1, 2, 3 };
	double Y[3] = { cos(1), cos(2), cos(3) };
	int x = 3;

	double ttt = lagrange(n, X, Y, x);
}




double MyCos1(int n, double* X, double* Y, double x){



}

void main()
{

	int n = 4;
	double X[3] = { 1, 2, 3 };
	double Y[3] = { 2, 3, 4 };
	int x = 2;


	double ttt = lagrange(n, X, Y, x);
	system("pause");
}

