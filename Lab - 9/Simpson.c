//
//  Simpson.c
//  Lab_9
//
//  Created by amadeus on 5/24/15.
//  Copyright (c) 2015 Amadeus. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define Pi 3.1415926
#include "Simpson.h"

double Simpson (double a, double b, double (*f) (double x)){
    double h, c, integral;
    h = b-a;
    c = (a+b)/2;
    
    integ = h/6*(f(a)+f(b)+4*f(c));
    printf("Resultado Integração Simpson: %lf\n",integral);
    return integral;
}