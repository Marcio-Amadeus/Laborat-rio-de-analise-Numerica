#include <stdio.h>
#include <math.h>

double square_root(double z, int p){

	double g, x, e = 0.5*pow(10, (-p));
	x = 1;
	g = (x + (z / x)) / 2;

	while (fabs(g - x) > e){
		x = g;
		g = (x + (z / x)) / 2;
	}
	return x;
}


int main(void){

	int i, p;
	double z, root2, root1;

	printf("Precisão:\n");
	scanf("%d", &p);

	for (i = 0; i<100; i++){
		//numeros variados para se calcular a raiz
		z = 1 + 0.25*i;
		root1 = square_root(z, p);
		root2 = sqrt(z);
		printf("Raiz de %.4g . Ponto fixo: %.16g/Raiz exata: %.16g \n", z, root1, root2);
	}

	return 0;
}