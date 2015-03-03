/**************************************************
Alexander Self
2/12/14
CS 407: Numerical Analysis
// This program is designed to find the roots of a 
given equation usng the Secant method. Then calculate
the largest positive root to three decimal places.
***************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;	

// Main Secant method for calculating the root of a given equation
// Takes a function and two end points, or X0 and X1
double Secant(double (*f) (double), double a, double b, double eps);

double Bisection(double(*f)(double), double a, double b, double eps);	// Bisection
double Newton(double(*f) (double), double(*fpr) (double), double x,
	double eps, double delta);		// Newton's method

double F(double x);	// equation: x^3-5x+3 = 0
double FP(double x);	// F prime
double swap(double a, double b);	// swaps values

const double eps = 0.5 * 0.000001;		// Epsilon for convergence
const double delta = 0.0001;


int main()
{
	double(*f) (double);	// function pointer
	double(*fp) (double);	// function pointer
	double a(1.5), b(3);

	f = &F;		// Point to F to pass into Secant
	fp = &FP;	// calculate f` for Newton's method
	cout << "--Secant Method--" << endl;
	Secant(f, a, b, eps);
	cout << "\n--Newton's Method--" << endl;
	Newton(f, fp, a, eps, delta);
	cout << "\n--Bisection Method--" << endl;
	Bisection(f, a, b, eps);

	system("pause");
	return 0;
}


/****************** Secant Method ***********************/
double Secant(double(*f) (double), double a, double b, double eps)
{
	int n, nmax(15);			// max number of loops
	double fa, fb, d;		// for functions

	fa = f(a);				// Find X0 and X1
	fb = f(b);

	
	if (abs(fa) > abs(fb)) {	// keep fa < fb
		swap(a,b);
		swap(fa, fb);
	}// end if
	
	cout << "-0-" << setw(10) << " -a- " << setw(10) << " -fa- " << endl;
	cout << 0 << setw(10) << a << setw(10) << fa << endl;
	cout << "-1-" << setw(10) << " -b- " << setw(10) << " -fb- " << endl;
	cout << 1 << setw(10) << b << setw(10) << fb << endl;
	cout << endl;
	cout << "-n-" << setw(20) << " -a- " << setw(20) << " -fa- " << endl;
	
	// main calculating loop
	for (n = 2; n < nmax; n++) {
		if (abs(fa) > abs(fb)) {	// keep fa < fb
			swap(a, b);
			swap(fa, fb);
		}// end if
		d = (b - a) / (fb - fa);		// X1 - X0 / f(x1) - f(x0)
		b = a;
		fb = fa;
		d *= fa;
		if (abs(d) < eps) {
			cout << "Convergence!" << endl;
			return d;
		}
		a -= d;
		fa = f(a);
		cout << n << setw(20) << setprecision(4) << a << setw(20) << fa << endl;
	}// end for
}

/****************** Bisection Method ***********************/
double Bisection(double(*f)(double), double a, double b, double eps)
{
	int n, nmax(25);
	double c, fa, fb, fc, error;

	// Find the output to determine what a and b will be
	fa = f(a);
	fb = f(b);
	// make sure signs are not the same, if either they are both negative or both positive
	if ((fa < 0 && fb < 0) || (fa > 0 && fb > 0))  {
		cout << "a: " << a << " b: " << b << endl;
		cout << "f(a): " << fa << " f(b): " << fb << endl;
		return 0;
	}// end if

	error = b - a;		// find the error to see if the root is converging
	cout << "n: " << setw(20) << " c: " << setw(20) << "f(c): " << setw(20) << " error: " << endl;
	// main loop to find convergence of roots
	for (n = 0; n < nmax; n++) {
		error = error / 2;
		c = a + error;
		fc = f(c);
		cout << n << setw(20) << c << setw(20) << fc << setw(20) << error << endl;
		if (abs(error) < eps) {
			cout << "Convergence!" << endl;
			return fc;
		}// end if
		if ((fa < 0 && fc > 0) || (fa > 0 && fc > 0)) {
			b = c;			// b value is the new c value
			fb = fc;
		}// end if
		else {
			a = c;			// a value is the new c value
			fa = fc;
		}// end else
	}// end for

	//out.close();
	return 0;
}// end Bisection


/****************** Newton's Method ***********************/
double Newton(double(*f) (double), double(*fpr) (double), double x,
	double eps, double delta)
{
	int n, nmax(25);		// Iterations to take place, 25 chosen arbitrarily
	double fx, fp, d;			// functions f(x) and F`(x)

	fx = f(x);				// find first f(x)

	cout << setw(10) << "-N-" << setw(20) << "-X-" << setw(20) << "-F(x)-" << endl;

	// main loop to find the root of the equation
	for (n = 0; n < nmax; n++) {
		fp = fpr(x);			// find f`(x) to check for early zeros
		if (abs(fp) < delta) {
			cout << "Small Derivative" << endl;
			return fp;
		}// end if
		d = fx / fp;			// Set d to the division of F(x) and f`(x) for later subtraction
		x -= d;					// subtract x from d to find Xn+1
		fx = f(x);				// calculate the next F(x) and repeat previous steps to find convergence
		cout << setw(10) << n << setw(20) << x << setw(20) << fx << endl;
		if (abs(d) < eps) {
			cout << "Convergence!" << endl;
			return d;
		}// end if
	}// end for
	return 0;
}// end Newton

double F(double x)
{
	double f;
	f = pow(x, 3) - 5 * x + 3;
	return f;
}

double FP(double x)
{
	double f;
	f = 3 * pow(x, 2) - 5;
	return f;
}

double swap(double a, double b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
	return a, b;
}








