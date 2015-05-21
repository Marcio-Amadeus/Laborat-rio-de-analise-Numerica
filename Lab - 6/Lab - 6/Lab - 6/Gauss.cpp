#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//M(i,j) por A(k) onde k = i*n + j


void NaiveGaussElimination(int n, double* A, double* b){
	int j, i, k;
	float f;
	float temp = 0;
	float temp2 = 0;
	double Prin[9];
	for (j = 0; j<(n - 2); j++){

		for (i = j + 1; i <= (n); i++){
			temp = A[(i - 1)*n + j];
			temp2 = A[j*n + j];
			f = temp / temp2;

			for (k = j; k <= (n - 1); k++){

				Prin[(i - 1)*n + k] = A[(i - 1)*n + k] - f*A[j*n + k];
				printf("A[%d] = %lf\n", (i - 1)*n + k, Prin[(i - 1)*n + k]);
			}

			b[i - 1] = b[i - 1] - f*b[j];
		}
	}

}





void BackSubstitution(int n, double* A, double* b, double* x)
{
	//here: 'rows' is size of matrix eg: for 3x3 it is 3
	//x[] where we put the result of backward substitution
	//b[] it is the vector to be used.
	//A[] is the square triangular matrix.

	register int i, j;

	// x(m,1) = b(m)/A(m,m); %% this is for the last row.
	x[n - 1] = b[n - 1] / A[(n - 1)*n + (n - 1)];

	// for i = m-1:-1:1     % i starts at 2, end at 4, w/ steps of 1
	//    x(i,1) = ( b(i)- A(i,i+1:m)*x(i+1:m))  /  A(i,i);
	// end

	for (i = (n - 2); i >= 0; i--)
	{
		x[i] = b[i];
		for (j = i + 1; j<n; j++)
		{
			x[i] -= A[(j)*n + i] * x[j];
		};
		x[i] = x[i] / A[(i)*n + i];
		printf("X[%d] = %lf\n", (j), x[(j)]);
	}; //for (i=1; i<rows; i++)
}; //void forward_substitution(double *A, double b*, int n)

int main(void){
	int n = 3;
	double* M;
	double m[9] = { 1, 2, -3, 2, 1, 1, -1, -2, 1 };
	M = m;
	double* B;
	double b[3] = { 3, 3, -6 };
	B = b;
	double X;
	double x[3] = { 0, 0, 0 };
	X = x;
	NaiveGaussElimination(n, M, B);
	BackSubstitution(n, M, B, x);
	system("pause");
	return 0;


}