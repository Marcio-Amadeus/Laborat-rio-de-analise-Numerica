#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>



double MidPoint(double t0, double t1, double h, double y0, double(*df) (double t, double y)){


	double y = y0;
	double t = t0;
	int entrou = 0;
	double  s1;

	s1 = h*df(t, y);

	while (t < t1){

		if (t + h >= t1 && entrou == 0){
			t = t1;
			entrou = 1;
		}

		y += h * df(t + (h / 2), y + (s1 / 2));
		
		s1 = h*df(t, y);
		

		
		t += h;

		
	}
	return y;
}