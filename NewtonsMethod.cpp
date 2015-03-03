/******************************************
Alexander Self
CS 407: Numerical Analysis
2/10/14
// This program uses Newton's method to
find the roots of a given equation.
*******************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Main method to calculate the roots of a given equation
// Takes two function pointers for the equations to be passed in,
// x value to start and epsilon and delta to control convergence
double Newton(double(*f) (double), double(*fpr) (double), double x,
	double eps, double delta);
// Functions for the assignment equations
double F(double x);		// f(x) = x^3 - 2x^2 + x -3 
double FP(double x);	// f`(x) = 3x^2 - 4x + 1
double G(double x);		// g(x) = x^4 + 2x^3 - 7x^2 + 3
double GP(double x);	// g`(x) = 4x^3 + 6x^2 - 14x 
double H(double x);		// h(x) = x^3 - 2x - 5
double HP(double x);	// h`(x) = 3x^2 - 2

const double eps = 0.5 * 0.00001;	// For convergence
const double delta = 0.0001;		// For the small derivative

int main()
{
	// Function pointers
	double(*f) (double), (*fp) (double), (*g) (double), (*gp) (double), 
		(*h) (double), (*hp) (double);
	double (*pass) (double), (*pass2) (double);
	double x(3), x1(1), x2(2), x3(1);	// x3 selected based off of graphing h(x)
	char choice, choice2 ,f1('a'), g1('a'), h1('a');
	char f2('a'), g2('a'), h2('a');
	// Can now pass functions as parameters
	f = &F;
	fp = &FP;
	g = &G;
	gp = &GP;
	h = &H;
	hp = &HP;
	pass = &F;
	pass2 = &FP;
	cout << "Enter the function you would like to pass f1-h1: ";
	cin >> choice;
	cout << "Enter the 2nd function you would like to pass f2-h2: ";
	cin >> choice2;
	if (choice == f1) {
		pass = &F;
	}
	else if (choice2 == f2) {
		pass2 = &FP;
	}
	if (choice == g1) {
		pass = &G;
	}
	else if (choice2 == g2) {
		pass2 = &GP;
	}
	if (choice == h1) {
		pass = &H;
	}
	else if (choice2 == h2) {
		pass2 = &HP;
	}
	Newton(pass, pass2, x, eps, delta);
	/*cout << "1)	f(x) = x^3 - 2x^2 + x - 3 starting at x0=3" << endl;
	Newton(f, fp, x, eps, delta);
	cout << "\n2)	g(x) = x^4 + 2x^3 - 7x^2 + 3 starting at x0=1" << endl;
	Newton(g, gp, x1, eps, delta);
	cout << "\n2)	g(x) = x^4 + 2x^3 - 7x^2 + 3 starting at x0=2" << endl;
	Newton(g, gp, x2, eps, delta);
	cout << "\n3)	h(x) = x^3-2x-5 starting at x0=" << x3 <<  endl;
	Newton(h, hp, x3, eps, delta);
	*/
	system("pause");
	return 0;
}

// Main Newton Method for finding roots
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
	f = pow(x, 3) - 2 * pow(x, 2) + x - 3;
	return f;
}// end F

double FP(double x)
{
	double fp;
	fp = 3*pow(x, 2) - 4*x + 1;
	return fp;
}// end FP
		
double G(double x)
{
	double g;
	g = pow(x, 4) + 2 * pow(x, 3) - 7 * pow(x, 2) + 3;
	return g;
}// end G

double GP(double x)
{
	double gp;
	gp = 4 * pow(x, 3) + 6 * pow(x, 2) - 14 * x;
	return gp;
}// end GP

double H(double x)
{
	double h;
	h = pow(x, 3) - 2 * x - 5;
	return h;
}// end H

double HP(double x)	 
{
	double hp;
	hp = 3*pow(x, 2) - 2;
	return hp;
}// end HP