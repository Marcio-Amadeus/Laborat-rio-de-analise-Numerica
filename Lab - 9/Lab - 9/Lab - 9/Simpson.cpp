#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>


double simpson(double a, double b, double (*f)(double x))
{
	double c = (a + b) / 2.0;
	double h = abs(b - a) / 6.0;
	double solucao = h*(f(a) + 4.0*f(c) + f(b));
	return solucao;

}