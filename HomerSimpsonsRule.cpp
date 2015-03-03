/***************************************************
Alexander Self
CS 407: Numerical Analysis
3/10/14
-This program computes an integral using the Simpson's
Rule.
****************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double eps = (0.000005 * 0.5);
const double pi = 4.0 * tan(1.0);
#define LEVEL_MAX 4						// Maximum iterations

// Main simpson function for computing the integral
double Simpson(double(*f) (double), double a, double b, double ep, int level,
	int level_Max);
/**********Functions*****************/
double A(double x);
double B(double x);
double C(double x);
/************************************/
void intro();
void time();

void main(void)
{
	int lvl(0);
	double(*f) (double);
	double a1(0), b1(1), c1((5/4)*pi), d(1/sqrt(2));
	double result, result2;
	
	intro();

	f = &A;
	result = Simpson(f, a1, b1, eps, lvl, LEVEL_MAX);
	cout << endl;
	cout << "\tIntegral: 1 / 1 + x^2 dx; on interval {0, 1}" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Approximate integral: " << setprecision(10) << fixed << result << endl;
	cout << endl;
	f = &B;
	result2 = Simpson(f, a1, d, eps, lvl, LEVEL_MAX);
	cout << endl;
	cout << "\tIntegral: sqrt(1 - x^2) - x dx; on interval {0, 1/sqrt(2)}" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Approximate integral: " << result2 << endl;


	system("pause");
}

// Main Simpson method for computing a given integral, takes the interval of the integral
// epsilon for comparing one_simpson and two_simpson and a level to exit out of recursion.
double Simpson(double (*f) (double), double a, double b, double ep, int level,
	int level_Max)
{
	double c, d, e, h;
	double one_simpson, two_simpson;
	double right_simpson, left_simpson;
	double simpson_result;

	level++;
	h = b - a;				// get h value for intervals
	c = (a + b) * 0.5;		// midpoint
	one_simpson = h * (f(a) + 4 * f(c) + f(b)) / 6.0;		// subdivide two double-width subintervals
	d = (a + c) * 0.5;
	e = (c + b) * 0.5;
	two_simpson = h * (f(a) + 4 * f(d) + 2 * f(c) + 4 * f(e) + f(b)) / 12.0;	// subdivide four single-width subintervals
	
	if (level >= level_Max) {
		simpson_result = two_simpson;
		cout << "Maximum level reached!" << endl;
	}// end if
	else {
		if ((abs(two_simpson - one_simpson)) < 15.0 * ep) {		// If they agree, no more subdivisions
			simpson_result = two_simpson + (two_simpson - one_simpson) / 15.0;
		}// end else if
		else {
			left_simpson = Simpson(f, a, c, (ep / 2), level, level_Max);
			right_simpson = Simpson(f, c, b, (ep / 2), level, level_Max);
			simpson_result = left_simpson + right_simpson;
		}// end else
	}
	return simpson_result;
}

double A(double x)
{
	return 4 * (1 / (1 + pow(x, 2)));
}

double B(double x)
{
	return 8 * (sqrt(1 - pow(x, 2)) - x);
}

double C(double x)
{
	return cos(2 * x) / exp(x);
}

void intro()
{
	cout << "Homer Simpon's Rule of Integration!" << endl << endl;
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








