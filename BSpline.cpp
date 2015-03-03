/*****************************************************
Alexander Self
CS 407: Numerical Analysis
4/1/14
// This program performs the b-spline coefficient
and b-spline evaluation.
*****************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void BSpline_Coef(int n, double t[], double y[], double a[], double h[]);
double BSpline_Eval(int n, double t[], double a[], double h[], double x);

const int n = 20;

int main()
{
	ofstream out;
	out.open("data.txt");
	
	double t[n+1] = { 0.0, 0.2, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5,
				5.0, 5.2, 5.5, 6.0, 6.2, 6.5, 7.0, 7.5, 8.0 };
	double y[n+1] = { 0.0, -0.8, -0.34, 0.59, 0.23, 0.1, 0.28, 1.03, 1.5, 1.44,
				0.74, -0.82, -1.27, -0.92, -0.92, -1.04, -0.79, -0.06, 1.0, 0.0 };
	
	double a[n+2], h[n+2];
	double z[n + 1];
	BSpline_Coef(n, t, y, a, h);
	
	for (double i = 1; i <= n; i+=0.1) {
		out << BSpline_Eval(n, t, a, h, i) << endl;
	}
	
	out.close();
	system("pause");
	return 0;
}

// t[i] is knot array, y[i] abscicca points, a[i] coefficients, h[i] contains knot array(t[i] - t[i-1])
void BSpline_Coef(int n, double t[], double y[], double a[], double h[])
{
	int i;
	double delta, gamma, p, q, r;
	
	for (i = 1; i <= n; i++) {
		h[i] = t[i] - t[i - 1];
	}// end for
	
	h[0] = h[1];
	h[n + 1] = h[n];
	delta = -1.0;
	gamma = 2.0 * y[0];
	p = delta * gamma;
	q = 2.0;

	for (i = 1; i <= n; i++) {
		r = h[i + 1] / h[i];
		delta *= -r;
		gamma = (-r)*gamma + (r + 1) * y[i];
		p += gamma * delta;
		q += delta * delta;
	}// end for

	a[0] = -(p / q);

	for (i = 1; i <= n + 1; i++) {
		a[i] = ((h[i - 1] + h[i]) * y[i - 1] - h[i] * a[i - 1]) / h[i - 1];
	}// end for

}

double BSpline_Eval(int n, double t[], double a[], double h[], double x)
{
	int i;
	
	double d, e;
	for (i = n - 1; i >= 0; i--) {
		if (x - t[i] >= 0) 
			break;
	}// end for
	i += 1;
	d = ( a[i + 1] * (x - t[i - 1]) + a[i] * (t[i] - x + h[i + 1]) ) / (h[i] + h[i + 1]);
	e = ( a[i] * (x - t[i - 1] + h[i - 1]) + a[i - 1] * (t[i - 1] - x + h[i])) / (h[i - 1] + h[i]);
	
	return (d * (x - t[i -1]) + e * (t[i] - x)) / h[i];
}









