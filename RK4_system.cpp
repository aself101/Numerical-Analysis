/**************************************************
Alexander Self
CS 407: Numerical Analysis
4/14/14
-- This program computes the RK4_System algorithm

**************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
using namespace std;

void RK4_System1(double h, double x[], int nSteps);
//void XP_System(double x[], double f[]);
void XP_System2(double x[], double f[]);
void intro();
void time();

const int n = 2;
#define RK_order 4

void main(void)
{
	int nSteps(100);
	double a(0), b(1.0);
	double h, t(0);
	double x[] = {0, 1, 0};

	h = (b - a) / nSteps;

	intro();

	RK4_System1(h, x, nSteps);

	system("pause");
}

// Main algorithm of the RK4_system for solving an ODE
void RK4_System1(double h, double x[], int nSteps)
{
	int i(0), j(0);
	double y[n + 1], k[4 + 1][4 + 1];

	cout << "{0}" << setw(18) << "{t}" << setw(18) << "x[i]" << endl;
	cout << "--------------------------------------------------" << endl;

	// Run through 100 steps to solve the ODE's
	for (j = 0; j < nSteps; j++) {

		XP_System2(x, k[1]);
		// Evaluate y at each step
		for (i = 0; i <= n; i++)
			y[i] = x[i] + 0.5 * h * k[1][i];
		
		XP_System2(y, k[2]);	// Evaluate x and y prime
		
		for (i = 0; i <= n; i++)
			y[i] = x[i] + 0.5 * h * k[2][i];
		
		XP_System2(y, k[3]);
		
		for (i = 0; i <= n; i++)
			y[i] = x[i] + h * k[3][i];
		
		XP_System2(y, k[4]);
		
		for (i = 0; i <= n; i++)
			x[i] += (h / 6) * (k[1][i] + 2 * k[2][i] + 2 * k[3][i] + k[4][i]);

		for (i = 0; i <= n; i++)
			printf("j = %2d, x[%d] = %14f\n", j, i, x[i]);
	}// end for

}// end RK4_System1()

// X prime Y primes
void XP_System(double x[], double f[])
{
	// x(t) = x[1]; y(t) = x[2], t = x[0]
	f[0] = 1.0;
	f[1] = x[1] - x[2] + 2 * x[0] - (x[0] * x[0]) - (x[0] * x[0] * x[0]);	// x prime
	f[2] = x[1] + x[2] - 4 * (x[0] * x[0]) + (x[0] * x[0] * x[0]);	// y prime
}// end XP_system

void intro()
{
	cout << "Runge-Kutta procedure for System(4) for Ordinary Differential Equations" << endl << endl;
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