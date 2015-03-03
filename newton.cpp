/*************************************************
Alexander Self
2/21/14
CS 407: Numerical Analysis
-This program aims at using the divided difference
method to find the Newton form of the interpolation 
polynomial.
**************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

// Main functions for finding coefficients and evaluating them
double coef(int n, double x[], double y[], double a[]);
double eval(int n, double x[], double a[], double t);

int main()
{
	double n(10), t(0);
	int i, j, jTemp(0);
	double x[10];				// 10 equidistant points of 0 - 1.687  
	double y[10];				// holds sin(x)
	double a[11];				// Points in table is: n + 1
	double b(1.687/n), h;	
	double p(0);
	double e(0);
	double pTemp(0), eTemp(0), tTemp(0);	// holds max values

	cout << " --The initial fill --" << endl;
	cout << "--x--" << setw(15) << "--sin(x)--" << endl;
	
	// Fill up x[i] and y[i]
	for (i = 0; i < n; i++) {
		h = i*b;
		x[i] = h;
		y[i] = sin(x[i]);
		cout << x[i] << setw(15) << y[i] << endl;
	}// end for
	system("pause");
	
	cout << "\n*******************************************************************" << endl;
	coef(n, x, y, a);		// getting the coefficients
	cout << "Coefficients: --a--" << endl;
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}// end for
	system("pause");
	
	cout << "\n*******************************************************************" << endl;
	cout << "--j--" << setw(10) << "--t--" << setw(15) << "--p--" << setw(18) << "--sin(t)--" << setw(15) << "--e--" << endl;
	
	for (j = 0; j < 4*n; j++) {
		t = (j * h) / n;
		p = eval(n, x, a, t);
		e = abs(sin(t) - p);
		/*************** Find the Max *************************/
		pTemp = max(p, pTemp); 
		tTemp = max(t, tTemp);
		eTemp = max(e, eTemp);
		jTemp = max(j, jTemp);
		/******************************************************/
		cout << j << setw(15) << t << setw(15) << p << setw(15) << sin(t) << setw(18) << e << endl;
		if (e > max(e, eTemp)) {
			j = max(j,jTemp);
			t = max(t, tTemp);
			p = max(p, pTemp);
			e = max(e, eTemp);
		}
	}// end for
	
	cout << "\n*******************************************************************" << endl;
	cout << "jMax: " << " { " << jTemp << " } " << " tMax: " << " { " << tTemp << " } " << " pMax: " << " { " << pTemp << " } "
		 << " eMax: " << " { " << eTemp << " } " << endl;
	
	system("pause");
	return 0;
}
// Computes the coefficients required in the Newton interpolating polynomial and
// stores them in a[]
double coef(int n, double x[], double y[], double a[])
{
	int i, j;
	for (i = 0; i < n; i++) {
		a[i] = y[i];
	}//end for

	for (j = 1; j < n; j++) {
		for (i = n; i > j; i--) {
			a[i] = (a[i] - a[i - 1]) / (x[i] - x[i - j]);	// stores the computed coefficients in a[i]
		}// end inner for
	}// end for

	return *a;
}// end coef

// X[i] from original table and a[i], which contains the coefficients for the Newton form
// of the interpolation polynomial.
double eval(int n, double x[], double a[], double t)
{
	int i;
	double temp;

	temp = a[n];	// store last value in a, in temp

	for (i = n - 1; i > 0; i--) {
		temp = (temp) * (t - x[i]) + a[i];
	}// end for
	return temp;
}// end eval




