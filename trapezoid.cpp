/************************************************
Alexander Self
CS 407: Numerical Analysis
3/5/14
-This program computes the trapezoid
method for a given integral.
*************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Main trapezoid function, computes the integral
void trapezoid(double(*f) (double), double a, double b);
void intro();
void time();
/**********Functions************/
double A(double x);
double B(double x);
double C(double x);
double D(double x);
double E(double x);
double F(double x);
double G(double x);
/*******************************/

const double pi = 3.14159265359;

int main()
{
	double (*f) (double);			// function pointer
	double a(0.0), b(1.0), c(3.0);	// For indefinite integral

	intro();

	f = &A;
	cout << "\na) e ^ -x^2" << endl;
	trapezoid(f, a, b);
	
	f = &B;
	cout << "\nb) sin(x)" << endl;
	trapezoid(f, a, pi);
	
	f = &C;
	cout << "\nc) e^x" << endl;
	trapezoid(f, a, b);
	
	f = &D;
	cout << "\nd) arctan(x)" << endl;
	trapezoid(f, a, b);
	
	f = &E;
	cout << "\ne) (x^2 + 2)^-1" << endl;
	trapezoid(f, a, b);
	
	f = &F;
	cout << "\nf) sin(x)/x" << endl;
	trapezoid(f, a, b);
	
	f = &G;
	cout << "\ng) x^2 - 2" << endl;
	trapezoid(f, b, c);
	
	system("pause");
	return 0;
}
// Main Trapezoid method
void trapezoid(double (*f) (double), double a, double b)
{
	int i, n(60);				// n = amount of intervals we want
	double h, sum, x;	

	h = (b - a) / n;			// find the intervals/partitions 
	sum = 0.5 * (f(a) + f(b));	// get the sum of f(x0) + f(xn)	

	for (i = 1; i < n - 1; i++) {
		x = a + (i*h);
		sum += f(x);
	}// end for
	sum *= h;
	cout << "Sum is: " << setprecision(8) << sum << endl;

}// end trapezoid()


double A(double x)
{
	return exp(-pow(x, 2));
}// end A()
double B(double x)
{
	return sin(x);
}// end B()
double C(double x)
{
	return exp(x);
}// end C()
double D(double x)
{
	return atan(x);
}// end D()
double E(double x)
{
	return (1 / (pow(x, 2) + 2));
}// end E()
double F(double x)
{
	if (x == 0)
		return 1.0;
	else
		return (sin(x) / x);
}// end F()
double G(double x)
{
	return (pow(x, 2) - 2);
}// end G()

void intro()
{
	cout << "Trapezoid Method" << endl << endl;
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
}// end time()