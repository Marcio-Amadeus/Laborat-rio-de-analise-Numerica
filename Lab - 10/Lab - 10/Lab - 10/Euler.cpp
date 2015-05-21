#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include "MidPoint.h"


double Euler(double t0, double t1, double h, double y0, double(*df)(double t, double y))
{
	double y = y0;
	double t = t0;
	int entrou = 0;

		while (t <= t1){
		y += h * df(t, y);
		
		if (t > t1 && entrou == 0){
			t = t1;
			entrou = 1;
		}
		t += h;
	}
	return y;
	std::cout << "done\n";
}







