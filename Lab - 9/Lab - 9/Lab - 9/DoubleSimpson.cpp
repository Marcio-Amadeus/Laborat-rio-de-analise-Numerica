#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>


	double DoubleSimpson(double a, double b, double(*f)(double x))
	{
		double c = (a + b) / 2.0;
		double h = abs(b - a) / 6.0;
		double solucao_1 = h*(f(a) + 4.0*f(c) + f(c));
		double solucao_2 = h*(f(c) + 4.0*f(c) + f(b));
		double solucao = solucao_1 + solucao_2;
		return solucao;

	}