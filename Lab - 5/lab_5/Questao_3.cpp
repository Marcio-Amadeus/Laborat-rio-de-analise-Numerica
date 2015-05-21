#include "Questao_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* cos */
#include <cmath> 
//#include <iostream.h>
#include <conio.h>

double *NewtonCoeficients(int n, double *X, double *Y){


	int i = 0;
	int j = 0;
	float soma = 0;
	float a;
	double* b = (double*)malloc(sizeof(double));

	for (j = 0; j<n - 1; j++)
	{
		for (i = n - 1; i>j; i--)
			Y[i] = (Y[i] - Y[i - 1]) / (X[i] - X[i - j - 1]);
		b[i] = Y[i];
	}
	return b;
}

double Newton(int n, double *X, double *Y, double * b, double x){

	int i = 0;
	int a;
	double soma = 0;

	for (i = n - 1; i >= 0; i--)
	{
		double mult = 1;
		for (j = 0; j<i; j++)
			mult *= (a - x[j]);

		mult *= b[j];
		soma += mult;
	}


}

double myCos2(int n, double *X, double *Y, double x){

	int n = 4;
	double X[3] = { 1, 2, 3 };
	double Y[3] = { cos(1), cos(2), cos(3) };
	double x = 3;

	double* b = (double*)malloc(sizeof(double));

	double ttt = Newton(n, X, Y, b, x);
}




void main()
{

	int n = 3;
	double X[3] = { 1, 2, 3, };
	double Y[3] = { 2, 3, 4, };
	double b[3];
	//int i = 0;

		double b = *NewtonCoeficients(n, X, Y);



		double erro_newton = (mycos2 - cos(3)) / cos(3);
		double erro_lagran = (Mycos1 - cos(3)) / cos(3);



	system("pause");
}







//int main()
//{
//	int n, i, j;
//	float x[10], f[10], a, sum = 0, mult;
//	clrscr();
//	cout << "No of sample points ? ";
//	cin >> n;
//	cout << "\nAll x with corresponding f(x) ";
//	for (i = 0; i<n; i++)
//		cin >> x[i] >> f[i];
//	cout << "\nEnter x for calculation ";
//	cin >> a;
//
//	for (j = 0; j<n - 1; j++)
//	{
//		for (i = n - 1; i>j; i--)
//			f[i] = (f[i] - f[i - 1]) / (x[i] - x[i - j - 1]);
//	}
//	for (i = n - 1; i >= 0; i--)
//	{
//		mult = 1;
//		for (j = 0; j<i; j++)
//			mult *= (a - x[j]);
//
//		mult *= f[j];
//		sum += mult;
//	}
//	cout << "The result is: " << sum;
//	getch();
//	return 0;
//}