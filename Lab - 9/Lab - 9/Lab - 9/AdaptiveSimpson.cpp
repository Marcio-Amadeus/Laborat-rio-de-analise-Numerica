#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>


float adaptiveSimpsons(float(*f)(float),  
	
	float a, float b,  // intervalo de integracao [a,b]
	float tol,  // tOLERANCIA DO ERRO
	int maxRecursionDepth) {   // recursion cap        
	float c = (a + b) / 2, h = b - a;
	float fa = f(a), fb = f(b), fc = f(c);
	float S = (h / 6)*(fa + 4 * fc + fb);
	return adaptiveSimpsonsAux(f, a, b, tol, S, fa, fb, fc, maxRecursionDepth);
}

//
// Recursive auxiliary function for adaptiveSimpsons() function below
//                                                                                                 
float adaptiveSimpsonsAux(float(*f)(float), float a, float b, float epsilon,
	float S, float fa, float fb, float fc, int bottom) {
	float c = (a + b) / 2, h = b - a;
	float d = (a + c) / 2, e = (c + b) / 2;
	float fd = f(d), fe = f(e);
	float Sleft = (h / 12)*(fa + 4 * fd + fc);
	float Sright = (h / 12)*(fc + 4 * fe + fb);
	float S2 = Sleft + Sright;
	if (bottom <= 100 || fabs(S2 - S) <= 8 * epsilon)
		return S2 + (S2 - S) / 8;
	return adaptiveSimpsonsAux(f, a, c, epsilon / 2, Sleft, fa, fc, fd, bottom - 1) +
		adaptiveSimpsonsAux(f, c, b, epsilon / 2, Sright, fc, fb, fe, bottom - 1);
}