/****************************************************
Alexander Self
CS 407: Numerical Analysis
3/17/14
-This program computes the cubic spline
*****************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

const int n = 9;

void Spline3_Coef(double t [], double y [], double z []);
double Spline3_Eval(int n, double t[], double y[], double z[], double x);
void intro();
void time();

void main(void)
{	
	double t[n+1], y[n+1], z[n+1];
	int i;
	double e, h, x;
	double a(0), b(1.6875);
	
	ofstream out;
	out.open("data.txt");

	intro();

	h = (b - a) / n;
	// fill up arrays
	for (i = 0; i <= n; i++)
	{
		t[i] = a + i* h;
		y[i] = sin(t[i]);
	}
	Spline3_Coef(t, y, z);
	cout << "i" << setw(15) << "x" << setw(18) << "e" << endl;
	cout << "---------------------------------------------------" << endl;
	for (i = 0; i <= 4 * n; i++)
	{
		x = a + i * h / 4;
		e = sin(x) - Spline3_Eval(n, t, y, z, x);
		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);
		cout << i << setw(15) << x << setw(18) << e << endl;
		out << Spline3_Eval(n, t, y, z, x) << endl;
	}
	out.close();
	system("pause");
}

void Spline3_Coef(double t[], double y[], double z[])
{
	int i;
	double h[n+1], b[n+1], u[n+1], v[n+1];

	for (i = 0; i < n; i++) {
		h[i] = t[i + 1] - t[i];
		b[i] = (y[i + 1] - y[i]) / h[i];
	}// end for

	u[1] = 2.0 * (h[0] + h[1]);				// computing inital u & v value 
	v[1] = 6.0 * (b[1] - b[0]);

	// compute u's and v's for z values
	for (i = 2; i < n; i++) {
		u[i] = 2 * (h[i] + h[i + 1]) - (h[i - 1] * h[i - 1]) / u[i - 1];
		v[i] = 6 * (b[i] - b[i - 1]) - (h[i - 1] * v[i - 1]) / u[i - 1];
	}// end for
	z[n] = 0;

	for (i = n - 1; i > 0; i--) {
		z[i] = (v[i] - h[i] * z[i + 1]) / u[i];
	}// end for
	z[0] = 0;
}

// evaluates the spline
double Spline3_Eval(int n, double t[], double y[], double z[], double x)
{
	int i;
	double h, temp;
	
	for (i = n - 1; i >= 1; i--) {
		if (x - t[i] >= 0) {
			break;
		}
	}// end for
	h = t[i + 1] - t[i];
	temp = (z[i] * 0.5) + (x - t[i]) * (z[i + 1] - z[i]) / (6.0 * h);
	temp = -(h / 6.0) * (z[i + 1] + 2.0 * z[i]) + (y[i + 1] - y[i]) / h + (x - t[i]) * temp;

	return (y[i] + (x-t[i]) * temp);
}

void intro()
{
	cout << "Cubic Spline Method" << endl << endl;
	cout << "Alexander Self" << endl;
	cout << "CS 407: Numerical Analysis" << endl;
	time();
	system("pause");
}// end intro()

void time()
{
	#pragma warning( disable : 4996)
	// current time/date
	time_t now = time(0);

	// convert to string
	char * dt = ctime(&now);
	cout << dt << endl;
}


