//
//  DoubleSimpson.cpp
//  Lab_9
//
//  Created by amadeus on 5/24/15.
//  Copyright (c) 2015 amadeus. All rights reserved.
//

#include "DoubleSimpson.h"
#include <stdio.h>
#include <math.h>
#define Pi 3.1415926


double DoubleSimpson (double a, double b, double (*f) (double x)){
    double h, c, integ,integac,integcb;
    h = (b-a)/2;
    c = (a+b)/2;
    
    integac = h/6*(f(a)+f(c)+4*f((a+c)/2));
    integcb = h/6*(f(c)+f(b)+4*f((c+b)/2));
    
    integ = integac + integcb;
    printf("Resultado da Integração dupla: %lf\n",integ);
    return integ;
    
}