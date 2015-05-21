#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include "MidPoint.h"
#include "Euler.h"
#include "RungeKutta.h"



double df(double t, double y)
{
	return (t*y) + (t*t*t);
}


int main()
{


	double euler, midpoint, kutta, euler1, midpoint1, kutta1, euler2, midpoint2, kutta2;

	euler = Euler(0.0, 2.4, 0.1, -1.0, df);
	midpoint = MidPoint(0.0, 2.4, 0.2, -1.0, df);
	kutta = RungeKutta(0.0, 2.4, 0.4, -1.0, df);


	euler1 = Euler(0.0, 2.4, 0.01, -1.0, df);
	midpoint1 = MidPoint(0.0, 2.4, 0.02, -1.0, df);
	kutta1 = RungeKutta(0.0, 2.4, 0.04, -1.0, df);


	euler2 = Euler(0.0, 2.4, 0.001, -1.0, df);
	midpoint2 = MidPoint(0.0, 2.4, 0.002, -1.0, df);
	kutta2 = RungeKutta(0.0, 2.4, 0.004, -1.0, df);


	
	printf("Método  h  y(2.4) \n--------------------------\n");
	printf("Euler        0.1  %lf    \nMidpoint     0.2  %lf \nRunge Kutta  0.4  %lf  \n--------------------------\n", euler, midpoint, kutta);
	printf("Euler        0.01  %lf    \nMidpoint     0.02  %lf \nRunge Kutta  0.04  %lf  \n--------------------------\n", euler1, midpoint1, kutta1);
	printf("Euler        0.001  %lf    \nMidpoint     0.002  %lf \nRunge Kutta  0.004  %lf  \n--------------------------\n", euler2, midpoint2, kutta2);


	system("pause");
	return 0;
}