/****************************************************
Alexander Self
CS 407: Numerical Analysis
4/13/14
// This program computes the Runge-Kutta RK45
and Runge-Kutta RK45 adaptive methods for solving
ordinary differential equations
*****************************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <time.h>
using namespace std;

// Main Runge-Kutta-Fehlberg algorithm for solving ordinary differential equations
double RK45(double (*f) (double, double), double &t, double &x, 
	double h, double &error);
// The Runge-Kutta adaptive method
double RK45_Adaptive(double(*f) (double, double), double &t, double &x,
	double h, double tB, int itMax, double eMax, double eMin,
	double hMin, double hMax, int iFlag);
double func(double t, double x);
double func2(double t, double x);

void intro();
void time();

const double eps = 0.00005 * 0.5;

void main(void)
{
	/********************************************************/
	// RK45
	double (*f) (double, double);		// function pointer
	double t, x(2.0), h, error(0);
	double a(1.0), b(1.5625);
	int n = 72;
	/*********************************************************/
	f = &func;
	h = (b - a) / static_cast<double>(n);
	t = a;

	intro();
	cout << "Regular RK45, Runge-Kutta-Fehlbrg Algorithm" << endl;
	cout << "{0}" << setw(22) << "{t}" << setw(18) << "{x}" << endl;
	cout << "-------------------------------------------------------------" << endl;

	for (int i = 1; i <= n; i++) {
		RK45(f, t, x, h, error);
		cout << i << setw(22) << t << setw(22) << x << endl;
	}// end for
	
	system("pause");
	/*****************************************************************/
	//RK45 Adaptive
	int iFlag(0), itMax(1000);
	double t1(0.0), x1(0.0), h1(0.01), tB(10.0);
	double eMax(0.00001), eMin(0.00000001), hMin(0.000001), hMax(1.0);
	/*****************************************************************/
	f = &func2;
	cout << "RK45 Adaptive, Runge-Kutta Algorithm" << endl;
	RK45_Adaptive(f, t1, x1, h1, tB, itMax, eMax, eMin, hMin, hMax, iFlag);
	cout << "As x approaches 10, the actual answer of x(10) = 135.917 is close" << endl;
	cout << "itMax: " << itMax << " " << "iFlag: " << iFlag << endl;
	system("pause");
}

// Runge-Kutta-Fehlberg Algorithm
double RK45(double (*f) (double, double), double &t, double &x, 
	double h, double &error)
{
	double k1, k2, k3, k4, k5, k6, x4;
	
	/*********** coefficients **************************/
	double c20(0.25), c21(0.25);
	double c30(0.375), c31(0.09375), c32(0.28125);
	double c40(12.0 / 13.0), c41(1932.0 / 2197.0);
	double c42(-7200.0 / 2197.0), c43(7296.0 / 2197.0);
	double c51(439.0 / 216.0), c52(-8.0);
	double c53(3680.0 / 513.0), c54(-845.0 / 4104.0);
	double c60(0.5), c61(-8.0 / 27.0), c62(2.0);
	double c63(-3544.0 / 2565.0), c64(1859.0 / 4104.0);
	double c65(-0.275);
	double a1(25.0 / 216.0), a2(0.0), a3(1408.0 / 2565);
	double a4(2197.0 / 4104.0), a5(-0.2);
	double b1(16.0 / 135.0), b2(0.0), b3(6656.0 / 12825.0);
	double b4(28561.0 / 56430.0), b5(-0.18);
	double b6(2.0 / 55.0);
	/****************************************************/
	// Evaluate each step to the fifth order
	k1 = h * f(t, x);
	k2 = h * f(t + c20 * h, x + c21 * k1);
	k3 = h * f(t + c30 * h, x + c31 * k1 + c32 * k2);
	k4 = h * f(t + c40 * h, x + c41 * k1 + c42 * k2 + c43 * k3);
	k5 = h * f(t + h, x + c51 * k1 + c52 * k2 + c53 * k3 + c54 * k4);
	k6 = h * f(t + c60 * h, x + c61 * k1 + c62 * k2 + c63 * k3 + c64 * k4 + c65 * k5);
	x4 = x + a1 * k1 + a3 * k3 + a4 * k4 + a5 * k5;
	x += b1 * k1 + b3 * k3 + b4 * k4 + b5 * k5 + b6 * k6;
	t += h;		// step through and evaluate at t
	error = abs(x - x4);

	return t, x, error;
}// end RK45()

// Runge-Kutta Adaptive algorithm
double RK45_Adaptive(double(*f) (double, double), double &t, double &x,
	double h, double tB, int itMax, double eMax, double eMin,
	double hMin, double hMax, int iFlag)
{
	double d, xSave, tSave, error;
	int k;
	cout << "{0}" << setw(22) << "{h}" << setw(18) << "{t}" << setw(18) << "{x}" << endl;
	cout << "-------------------------------------------------------------" << endl;
	iFlag = 1;
	k = 0;

	while (k <= itMax) {
		k++;
		// Check the step size on each min and max
		if (abs(h) < hMin)
			h = signed(h) * hMin;		
		if (abs(h) > hMax)
			h = signed(h) * hMax;
		d = abs(tB - t);
		// Check the step size with delta
		if (d <= abs(h)) {
			iFlag = 0;
			if (d <= eps * __max(abs(tB), abs(t)))
				break;
			h = signed(h) * d;
		}// end if
		// Save current values of x and t
		xSave = x;
		tSave = t;
		RK45(f, t, x, h, error);
		cout << k << setw(22) << h << setw(18) << t << setw(18) << x << error << endl;

		if (iFlag == 0)
			break;
		if (error < eMin)		// If the error is less than the minimum error, multiply h by 2
			h *= 2;
		if (error > eMax) {		// If the error is greater than the max error, divided h by 2
			h /= 2;
			x = xSave;
			t = tSave;
			k--;
		}// end if
	}// end while
	return itMax, iFlag;
}// end RK45_Adaptive()


double func(double t, double x)
{
	return (2 + (x - t - 1) * (x - t - 1));
}

double func2(double t, double x)
{
	return (3 + 5 * sin(t) + 0.2 * x);
}

void intro()
{
	cout << "Runge-Kutta-Fehlberg method for Ordinary Differential Equations" << endl << endl;
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