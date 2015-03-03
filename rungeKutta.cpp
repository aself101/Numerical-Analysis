/************************************************
Alexander Self
CS 407: Numerical Analysis
4/9/14
-- This program implements the Runge-Kutta method
of order 4
************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Main procedure 
void RK4(double (*f) (double, double), double t, double x, double h, int n);
double func(double t, double x);
double func2(double t, double x);
void intro();
void time();
void main(void)
{
	double (*f) (double, double);	// function pointer, 2 args
	double t, x(2.0), h;
	const double a(1.0), b(1.5625);
	const double a1(1.0), b1(2.77);
	double t1, x1(0.20466341728915526943), h1;
	const int n = 72;

	intro();

	h = (b - a) / n;
	t = a;

	f = &func;
	cout << "x(t) = (2 + (x - t - 1) * (x - t - 1))" << endl;
	RK4(f, t, x, h, n);
	
	cout << endl;
	
	t1 = a1;
	h1 = (b1 - a1) / n;
	f = &func2;

	cout << "x(t) = (exp(t) / (16 - exp(t)))" << endl;
	RK4(f, t1, x1, h1, n);

	system("pause");
}
// Classical Runge-Kutta Algorithm
void RK4(double (*f) (double, double), double t, double x, double h, int n)
{
	int j;
	double k1, k2, k3, k4, tA;
	
	cout << "{0}" << setw(18) << "{t}" << setw(18) << "{x}" << endl;
	cout << "-----------------------------------------------------" << endl;
	
	tA = t;
	// Compute the derivative
	for (j = 1; j <= n; j++) {
		k1 = h * f(t, x);			
		k2 = h * f(t + 0.5 * h, x + k1 * 0.5);
		k3 = h * f(t + 0.5 * h, x + k2 * 0.5);
		k4 = h * f(t + h, x + k3);
		x += (k1 + 2 * (k2 + k3) + k4) / 6;
		
		t = tA + j * h;
		if (j % 9 == 0) {
			cout << j << setw(18) << t << setw(18) << x << endl;
		}
	}// end for
}// end RK4()

double func(double t, double x)
{
	return (2 + (x - t - 1) * (x - t - 1));
}

double func2(double t, double x)
{
	return (x + x * x);
}


void intro()
{
	cout << "Runge-Kutta Method for Ordinary Differential Equations" << endl << endl;
	cout << "Alexander Self" << endl;
	cout << "CS 407: Numerical Analysis" << endl;
	time();
	system("pause");
}// end intro()

void time()
{
#pragma warning(disable : 4996)
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* dt = ctime(&now);
	cout << dt << endl;
}