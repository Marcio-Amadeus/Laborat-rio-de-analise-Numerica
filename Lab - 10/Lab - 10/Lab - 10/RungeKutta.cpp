#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include "MidPoint.h"
#include "Euler.h"
#include "RungeKutta.h"





double RungeKutta(double t0, double t1, double h, double y0, double(*df) (double t, double y)){


	double y = y0;
	double t = t0;
	int entrou = 0;
	double  s1, s2, s3, s4;

	while (t < t1){



		if (t + h >= t1 && entrou == 0){
			t = t1;
			entrou = 1;
		}

		s1 = h*df(t, y);
		s2 = h*df(t + h / 2, y + s1 / 2);
		s3 = h*df(t + h / 2, y + s2 / 2);
		s4 = h*df(t + h, y + s3);


		y += (s1 + 2 * s2 + 2 * s3 + s4) / 6;




		t += h;
	}
		return y;
	
}