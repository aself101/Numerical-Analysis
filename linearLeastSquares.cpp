/***********************************************
Alexander Self
CS407: Numerical Analysis
4/21/14
-- This program uses the least squares method
to predict CPU time as a function of disk I/O's
************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void leastSquares(double x[], double y[]);

void main(void)
{
	double x[] = {14, 16, 27, 49, 39, 50, 83};
	double y[] = {2, 5, 7, 9, 10, 13, 20};

	leastSquares(x, y);


	system("pause");
}


// main program to compute a linear fit to a set of points
void leastSquares(double x[], double y[])
{
	// main variables for computing a linear fit
	double m(0), p(0), q(0), r(0), s(0), d(0), a(0), b(0);		
	int i, j;
	// m = (# of points) - 1
	m = 7 - 1;
	cout << "m: " << m << endl;
	// p = Sum x points
	for (i = 0; i < 7; i++)
		p += x[i];
	cout << "p: " << p << endl;
	// q = Sum y points
	for (i = 0; i < 7; i++)
		q += y[i];
	cout << "q: " << q << endl;
	// r = Sum of points x * y
	for (i = 0; i < 7; i++)
		r += x[i] * y[i];
	cout << "r: " << r << endl;
	// s = Sum of x ^ 2
	for (i = 0; i < 7; i++)
		s += x[i] * x[i];
	cout << "s: " << s << endl;
	// d = (m + 1)s - p^2
	d = (m + 1) * s - (p * p);
	cout << "d: " << d << endl;
	// a = [(m + 1)r - pq] / d
	a = ((m + 1) * r - p * q) / d;
	cout << "a: " << a << endl;
	// b = (sq - pr) / d
	b = (s * q - p * r) / d;
	cout << "b: " << b << endl;
	cout << "-- Linear Fit --" << endl;
	cout << "y = " << a << "x + " << b << endl;

}// end leastSquares()














