/**********************************************************
Alexander Self
CS 407: Numerical Analysis
2/28/14
This program computes derivatives using the center differences
theorem and Richardson extrapolation. Ultimately leading
to faster convergence.
**********************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;


const int n = 10;

// main derivative function, uses central difference formula and Richarson extrapolation
void derivative(double (*f) (double), double x, double h, double d [][n]);
// functions to pass to derivative
double A(double x);	
double B(double x);
double C(double x);
double D(double x);
// prints out matrix
void printMatrix(double d[][n]);
void intro();			
void time();

int main()
{
	double (*f) (double);
	double	a[n][n];
	double	b[n][n];
	double	c[n][n];
	double	d[n][n];
	double h(0.0), x(0) ,x1(1.2309594154), x2(1);
	
	intro();

	cout << "Select the h value: ";
	cin >> h;
	/**************** a) f(x)=sin(x) at x=1.2309594154 ********************/
	cout << "a) f(x) = sin(x) at x = 1.2309594154 h = " << h << endl;
	f = &A;
	derivative(f, x1, h, a);
	printMatrix(a);
	system("pause");
	/**************** b) f(x)=cos(x) at x=0 ********************/
	cout << "\nb) f(x) = cos(x) at x = 0 h = " << h << endl;
	f = &B;
	derivative(f, x, h, b);
	printMatrix(b);
	system("pause");
	/**************** c) f(x)=arctan(x) at x=1 ********************/
	cout << "\nc) f(x) = arctan(x) at x = 1 h = " << h << endl;
	f = &C;
	derivative(f, x2, h, c);
	printMatrix(c);
	system("pause");
	/**************** d) f(x)=|x| at x=0 ********************/
	cout << "\nd) f(x) = |x| at x = 0 h = " << h << endl;
	f = &D;
	derivative(f, x, h, d);
	printMatrix(d);
	/*********************************************************************/

	system("pause");
	return 0;
}// end main()


void derivative(double (*f) (double), double x, double h, double d[][n])
{
	int i, j;
	
	for (i = 0; i < n; i++) {
		d[i][0] = ( f(x + h) - f(x - h) ) / (2.0 * h);	// derivative
		for (j = 1; j < i; j++) {
			d[i][j] = d[i][j-1] + (d[i][j - 1] - d[i - 1][j - 1]) / (pow(4, j) - 1); // eliminate the error
		}// end for
		h /= 2;
	}// end for
}// end derivative()

/********************* Main Functions **********************************/
double A(double x)
{
	return (sin(x));
}// end A()
double B(double x)
{
	return (cos(x));
}// end B()
double C(double x)
{
	return (atan(x));
}// end C()
double D(double x)
{
	return (abs(x));
}// end D()
/************************************************************************/

// Prints out matrix in triangular divided difference form
void printMatrix(double d[][n])
{
	cout << "----------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		//cout << i  << endl;
		for (int j = 0; j < i; j++) {
			cout << "[" << i << "]" << "[" << j << "] " << d[i][j] << "\t";
		}// end for
		cout << endl;
	}// end for
}

void intro()
{
	cout << "Richardson Extrapolation and Central Difference method" << endl << endl;
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
