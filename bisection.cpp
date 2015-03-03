/*******************************************************
Alexander Self
2/8/14
CS 407: Numerical Analysis
// This program uses the bisection algorithm to find the
roots of a given equation.
*******************************************************/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const double eps = 0.5 * 0.000001;

// main bisection method, takes 2 equations for a and b
double Bisection(double (*f)(double) ,double a, double b, double eps);
double F(double a);	// pow(a, 3) - 3 * a + 1;
double G(double a); // pow(a, 3) - 2 * sin(a);
double H(double a); // a + 10 - a*cosh(50 / a);
double J(double a); // pow(a, 3) - 3 * a - 5;
int main()
{
	
	double a(0), b(1), a1(0.5), b1(2), a2(120), b2(130), a3(2), b3(3);
	double (*f) (double);
	double (*g) (double);
	double (*h) (double);
	double (*j) (double);
	/*cout << "Enter the a value: ";
	cin >> a;
	cout << "Enter the b value: ";
	cin >> b;
	*/
	f = &F;
	g = &G;
	h = &H;
	j = &J;

	cout << "Function F: pow(a, 3) - 3 * a + 1" << endl;
	Bisection(f, a, b, eps);
	cout << "\nFunction G: pow(a, 3) - 2 * sin(a)" << endl;
	Bisection(g, a1, b1, eps);
	cout << "\nFunction H: a + 10 - a*cosh(50 / a)" << endl;
	Bisection(h, a2, b2, eps);
	cout << "\nFunction J: pow(a, 3) - 3 * a - 5" << endl;
	Bisection(j, a3, b3, eps);

	

	system("pause");
	return 0;
}

// Main Bisection method, input a and b outputs root
// Need to manually change the function you wish to use to find the root of
double Bisection(double(*f)(double), double a, double b, double eps)
{
	int n, nmax(50);
	double c, fa, fb, fc, error;
	
	// Output values and append to separate text file
	//ofstream out;
	//out.open("output.txt", out.app);
	
	// Find the output to determine what a and b will be
	fa = f(a);
	fb = f(b);
	// make sure signs are not the same, if either they are both negative or both positive
	if ((fa < 0 && fb < 0) || (fa > 0 && fb > 0))  {
		cout << "a: " << a << " b: " << b << endl;
		cout << "f(a): " << fa << " f(b): " << fb << endl;
//		out << "a: " << a << " b: " << b << endl;
//		out << "J(a): " << fa << " J(b): " << fb << endl;
		return 0;
	}// end if
	
	error = b - a;		// find the error to see if the root is converging

	// main loop to find convergence of roots
	for (n = 0; n < nmax; n++) {
		error = error / 2;
		c = a + error;
		fc = f(c);
		cout << "n: " << n << " c: " << c << endl;
		cout << "f(c): " << fc << " error: " << error << endl;
//		out << "n: " << n << " c: " << c << endl;
//		out << "J(c): " << fc << " error: " << error << endl;
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

double F(double a)
{
	double f;
	f = pow(a, 3) - 3 * a + 1;		
	return f;
}// end F

double G(double a)
{
	double g;
	g = pow(a, 3) - 2 * sin(a);
	return g;
}// end G

double H(double a)
{
	double h;
	h = a + 10 - a*cosh(50 / a);
	return h;
}// end H

double J(double a)
{
	double j;
	j = pow(a, 3) - 3 * a - 5;
	return j;
}// end J
