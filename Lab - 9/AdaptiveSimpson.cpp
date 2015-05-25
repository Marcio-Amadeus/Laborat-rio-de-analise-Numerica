//
//  AdaptiveSimpson.cpp
//  Lab_9
//
//  Created by amadeus on 5/24/15.
//  Copyright (c) 2015 amadeus. All rights reserved.
//

#include "AdaptiveSimpson.h"
#include <stdio.h>
#include <math.h>

#define Pi 3.1415926



double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol){
    
    double erro, s, s2,c;
    c = (a+b)/2;
    
    s2 = DoubleSimpson(a,b,f);
    s = Simpson(a,b,f);
    erro = 15*fabs(s-s2);
    if(erro<=tol){ printf("ERRO: %lf\n",erro); printf("--------------Integral: %lf\n",s2); return s2;}
    
    else { printf("ERRO: %lf\n",erro); return AdaptiveSimpson(a,c,f,tol/2) + AdaptiveSimpson(c,b,f,tol/2);}
    
}