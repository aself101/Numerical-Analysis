/************************************************
Alexander Self
CS 407: Numerical Analysis
4/4/14
-This program uses the taylor series method
to compute a solution for a given equation on a
given interval.
*************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Main Taylor methed for computing a solution to a given equation
void Taylor(double a, double b, long double x);
void intro();
void time();


void main(void)
{
	double a(1.0), b(2.77);
	long double	x(0.20466341728915526943);	// exp(1)/(16 - exp(1))

	intro();
	Taylor(a, b, x);

	system("pause");
}

void Taylor(double a, double b,long double x)
{
	double k;
	int	n(9000);
	double h, t, x1, x2, x3, x4, x5;	// First - fourth derivatives

	h = (b-a) / static_cast<double>(n);		// Interval
	t = a;
	
	cout << "{ 0 }" << setw(15) << "{ t }" << setw(15) << "{ x }" << setw(35) << "(exp(k) / (16 - exp(k)))" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	// evaluate derivatives
	for (k = 1; k <= n; k++) {
		x1 = x + x * x;
		x2 = x1 + (2 * x * x1);
		x3 = x2 + (2 * x * x2) + (2 * x1 * x1);
		x4 = x3 + (2 * x * x3) + (6 * x1 * x2);
		x5 = x4 + (2 * x * x4) + (6 * x2 * x2) + (8 * x1 * x3);
		x += h * (x1 + (h / 2)  * (x2 + (h / 3) * (x3 + (h / 4) * (x4 + (h / 5) * (x5) ) ) ) );
		t = a + k * h;
		
		cout << k << setw(18) << t << setw(18)<< setprecision(8) << x << endl;
	}// end for

}// end Taylor()

void intro()
{
	cout << "Taylor Series for Ordinary Differential Equations" << endl << endl;
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






