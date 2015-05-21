#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>


double Euler(double t0, double t1, double h, double y0, double(*df)(double t, double y));