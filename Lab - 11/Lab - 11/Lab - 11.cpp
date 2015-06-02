//
//  main.cpp
//  ODO_mane
//
//  Created by amadeus on 6/1/15.
//  Copyright (c) 2015 amadeus. All rights reserved.
//

#include <iostream>

#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>

// -----  Euler ----- //
double Euler(double t0, double t1, double h, double y0, double(*df)(double t, double y))
{
    double y = y0;
    double t = t0;
    int entrou = 0;
    
    while (t < t1){
        y += h * df(t, y);
        
//        if (t > t1 && entrou == 0){
//            t = t1;
//            entrou = 1;
//        }
        
        t += h;
    }
    return y;
    std::cout << "done\n";
}

// -----  Runge Kutta ----- //

double RungeKutta(double t0, double t1, double h, double y0, double(*df) (double t, double y)){
    
    
    double y = y0;
    double t = t0;
    int entrou = 0;
    double  s1, s2, s3, s4;
    
    while (y <= 10.05427){
        
        
        
        //if (t + h >= t1 && entrou == 0){
        //    t = t1;
        //    entrou = 1;
        //}
        
        s1 = h*df(t, y);
        s2 = h*df(t + h / 2, y + s1 / 2);
        s3 = h*df(t + h / 2, y + s2 / 2);
        s4 = h*df(t + h, y + s3);
        
        
        y += (s1 + 2 * s2 + 2 * s3 + s4) / 6;
        
        
        
        
        t += h;
        //printf("####### y = %lf\n###### t = %lf\n",y, t);
    }
    return t;
    
}

// -----  Busca t com Kutta ----- //

double TimeToY1(double t0, double y0, double y1, double h, double(*f) (double t, double y)){
    
    double kutta=0, t1;
    t1 = h;
    
    while(kutta <= y1){
        kutta = RungeKutta(t0, t1, h, y0, f);
        t0 = t0 + h;
        t1  = t1 + h;
        y0 = kutta;
    }
    return t1;
    
}

double AdaptiveEuler (double t0, double y0, double h0, double t1, double (*f) (double t, double y), double emax){
    
    double y1,y2,erro,hnew, soma=0;
    double y = 0;
    
    while(t0+h0 < t1){
        
        y1 = Euler(t0,t0+h0,h0,y0,f);
        y2 = Euler(t0,t0+h0,h0/2,y0,f);
        erro = fabs(y2-y1);
        
        if(erro>emax){
            hnew = h0*sqrt(emax/erro);
            h0 = hnew;
        }else {
            hnew = h0*sqrt(emax/erro);
            if(hnew > 1.2*h0) hnew = 1.2*h0;
            t0 = t0 + h0;
            y0 = y2;
            h0 = hnew;
            soma = soma + y2;
        }
       //printf("####### t0 = %lf\n###### y0 = %lf\n##### Tempo = %lf\n",y1,y2,t0);
    }
    
    return y0;
    
}


double f(double t, double y){
    return t*y + t*t*t;
}


double Questao2b(double );





int main(void){
    
    double euler, kutta, time;
    
    euler =  AdaptiveEuler(0.0, -1, 0.001, 2.4, f, 0.0001);
    time =  TimeToY1(0.0, -1, 10.054273, 0.001, f);
    kutta =  RungeKutta(0.0, 2.4, 0.001, -1, f);
    
    printf("Resultado Euler: %lf\n", euler);
    printf("Resultado Kutta: %lf\n", kutta);
    printf("Resultado Time do kutta: %lf\n", time);
    system("pause");
    return 0;
}