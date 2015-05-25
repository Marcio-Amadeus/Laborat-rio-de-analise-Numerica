//
//  main.cpp
//  Lab_9
//
//  Created by amadeus on 5/24/15.
//  Copyright (c) 2015 amadeus. All rights reserved.
//

#include "main.h"
#include <stdio.h>
#include <math.h>
#include "AdaptiveSimpson.h"
#include "Simpson.h"
#include "DoubleSimpson.h"

#define Pi 3.1415926

double f (double x){
    return x/sqrt(pow(x,4)+1);
}

int main (void){
    
    double tol,fx,gx;
    tol = 0.5*pow(10,-5);
    
    printf("\n\n### AVALIACAO DE F\n");
    fx = AdaptiveSimpson(0,1,f,tol);
    
    printf("\n\n### AVALIACAO DE G\n");
    gx = AdaptiveSimpson(0,Pi,g,tol);
    
    printf("\nResultados:\n fx= %.16g \n gx= %.16g\n",fx,gx);
    return 0;
}