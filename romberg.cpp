/***********************************************
Alexander Self
CS 407: Numerical Analysis
3/9/14
- This program computes the Romberg algorithm
to approximate a given integral.
************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int n = 5;					// number of subintervals at 2^n

// main Romberg algorithm used to compute a given integral
void Romberg(double (*f) (double), double a, double b, double r[][n]);
void printMatrix(double r[][n]);
void intro();
void time();

/*********Functions***********/
double A(double x);
double B(double x);
/*****************************/

int main()
{
	double (*f) (double);									// function pointer
	double a1(0), b1(1.0), c1(2.0), d1(1.3), e1(2.19);		// Intervals
	double r1 [n][n];										// Main matrix
	
	intro();
	// First equation
	cout << endl;
	cout << "a) Integral: 4 / 1 + x^2, on the interval {0 , 2}, n = " << n << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	f = &A;
	Romberg(f, a1, c1, r1);
	printMatrix(r1);
	system("pause");

	// Second equation
	cout << endl;
	cout << "a) Integral: 4 / 1 + x^2, on the interval {0 , 1}, n = " << n << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	Romberg(f, a1, b1, r1);
	printMatrix(r1);
	system("pause");

	// Third equation
	f = &B;
	cout << endl;
	cout << "a) Integral: sin(x) / x, on the interval {1.3 , 2.19}, n = " << n << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	Romberg(f, d1, e1, r1);
	printMatrix(r1);


	system("pause");
	return 0;
}

void Romberg(double(*f) (double), double a, double b, double r[][n])
{
	int i, j, k;
	double sum, h;

	h = b - a;
	r[0][0] = (h / 2) * (f(a) + f(b));		// Initial trapezoid calculation

	for (i = 1; i < n; i++) {
		h /= 2;								// get smaller intervals
		sum = 0;
		for (k = 1; k <= pow(2, i) - 1; k+=2) {		// 2^i - 1 steps
			sum += f(a + k*h);
		}// end for
		r[i][0] = 0.5 * r[i - 1][0] + (sum * h);
		for (j = 1; j <= i; j++) {
			// Final Romberg calculation, R(n,m), gets successive columns
			r[i][j] = r[i][j - 1] + (r[i][j - 1] - r[i - 1][j - 1]) / (pow(4, j) - 1);
		}// end for
	}// end for
}

// Main functions
double A(double x)
{
	return (4 / (1 + pow(x, 2)));
}

double B(double x)
{
	return (sin(x) / x);
}

void intro()
{
	cout << "Romberg Method of Integration" << endl << endl;
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

// Prints the matrix in final form, with the last value on the right as the 
// closest approximation.
void printMatrix(double r[][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (r[i][j] > 0)				// gets rid of extra cluttered values
				cout << setprecision(10) << fixed << showpoint << r[i][j] << "\t";
		}
		cout << endl;
	}
}