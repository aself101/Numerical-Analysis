/*****************************************************
Alexander Self
1/26/14
CS 407: Numerical Analysis
This program uses three functions to define the hyperbolic
tangent. The idea being, to look for an accurate value
and compare the functions. 
Results: The tanh function defined in full is typically
off by the last 3-4 significant digits. Even the sinh/cosh
differs a bit from the actual tanh built in function part of
the cmath library.
*****************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double e = 2.718281828459;

double long hyper(double long x);
double long hyper2(double long x);
double long hyper3(double long x);
int main()
{

	double long x1(0.1);
	double long result, result2, result3;
	// see how values diverge when x < 0.5 to x > 0.5
	for (int i = 0; i < 20; i++) {
		cout << "x = " << x1 << endl;
		result = hyper(x1);
		cout << "Tanh(x) built in function is: " << setprecision(18) << result << endl;

		result2 = hyper2(x1);
		cout << "Tanh(x) defined is: " << setprecision(18) << result2 << endl;

		result3 = hyper3(x1);
		cout << "Tanh(x) defined as sinh/cosh: " << setprecision(18) << result3 << endl;
		cout << "------------------------------------------------------" << endl;
		x1 += 0.05;
		result = 0, result2 = 0, result3 = 0; // reset results
	}// end for
	system("pause");
	return 0;
}
// use of built in tanh function
double long hyper(double long x)
{

	return tanh(x);

}
// tanh defined from the lab
double long hyper2(double long x)
{
	double long n;

	n = (pow(e, x) - pow(e, -x)) / (pow(e, x) + pow(e, -x));
	return n;
}
// tanh defined from a trigonometric identity
double long hyper3(double long x)
{

	return sinh(x)/cosh(x);

}