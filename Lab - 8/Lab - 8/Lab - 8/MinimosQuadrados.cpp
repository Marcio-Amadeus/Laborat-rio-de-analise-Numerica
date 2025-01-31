# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

# include "MinimosQuadrados.hpp"

using namespace std;

//****************************************************************************80

void MinimosQuadrados(int n, double* x, double* y){


	int i;


	y[i] = c0 +

}























//
////****************************************************************************80
////
////  Purpose:
////
////    LLSQ solves a linear least squares problem matching a line to data.
////
////  Discussion:
////
////    A formula for a line of the form Y = A * X + B is sought, which
////    will minimize the root-mean-square error to N data points ( X[I], Y[I] );
////
////  Licensing:
////
////    This code is distributed under the GNU LGPL license. 
////
////  Modified:
////
////    17 July 2011
////
////  Author:
////
////    John Burkardt
////
////  Parameters:
////
////    Input, int N, the number of data values.
////
////    Input, double X[N], Y[N], the coordinates of the data points.
////
////    Output, double &A, &B, the slope and Y-intercept of the least-squares
////    approximant to the data.
////
//{
//	double bot;
//	int i;
//	double top;
//	double xbar;
//	double ybar;
//	double &a; double &b;
//	
//	xbar = 0.0;
//	ybar = 0.0;
//	for (i = 0; i < n; i++)
//	{
//		xbar = xbar + x[i];
//		ybar = ybar + y[i];
//	}
//	xbar = xbar / (double)n;
//	ybar = ybar / (double)n;
//	//
//	//  Compute Beta.
//	//
//	top = 0.0;
//	bot = 0.0;
//	for (i = 0; i < n; i++)
//	{
//		top = top + (x[i] - xbar) * (y[i] - ybar);
//		bot = bot + (x[i] - xbar) * (x[i] - xbar);
//	}
//
//		a = top / bot;
//
//		b = ybar - a * xbar;
//
//		return
//	
//
//}
////****************************************************************************80



int main(void){

	// numero de amostras
	int n = 9;

	// Horario convertido entre 0..1 //
	double* X;
	double x[8] = { 0, 0.142857142857143, 0.285714285714286, 0.428571428571429, 0.571428571428571, 0.714285714285714, 0.857142857142857, 1 };
	X = x;

	// Temperatura //
	double* Y;
	double y[8] = { -2.2, -2.8, -6.10, -3.9, 0.0, 1.1, -0.6, -1.1};
	Y = y;

	MinimosQuadrados(n, X, Y);
	system("pause");
	return 0;
}









//
//void timestamp()
//
////****************************************************************************80
////
////  Purpose:
////
////    TIMESTAMP prints the current YMDHMS date as a time stamp.
////
////  Example:
////
////    31 May 2001 09:45:54 AM
////
////  Licensing:
////
////    This code is distributed under the GNU LGPL license. 
////
////  Modified:
////
////    08 July 2009
////
////  Author:
////
////    John Burkardt
////
////  Parameters:
////
////    None
////
//{
//# define TIME_SIZE 40
//
//	static char time_buffer[TIME_SIZE];
//	const struct std::tm *tm_ptr;
//	size_t len;
//	std::time_t now;
//
//	now = std::time(NULL);
//	tm_ptr = std::localtime(&now);
//
//	len = std::strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr);
//
//	std::cout << time_buffer << "\n";
//
//	return;
//# undef TIME_SIZE
//}