/************************************************
AlexanderSelf
CS 407: Numerical Analysis
3/14/14
-This program is designed to create a spline function
and in the process smooth out linear polynomials.
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const int n = 6;
// main spline function
double spline(int n, double t [], double y [], double x);
// computes z values
double zValue(int n, double t[], double y [], double z []);

void main(void)
{
	double t1[] = {-1.0, 0, 0.5, 1.0, 2.0, 2.5};
	double y1[] = {2.0, 1.0, 0, 1.0, 2.0, 3.0};
	//double k1[] = {0, 1.0, 2.0, 3.0, 4.0, 5.0};
	double k[n];
	double z[n+1];		// RETURNS z[i+1]

	// fill up an array to store spline results
	for (int i = 0; i < n; i++) {
		k[i] = spline(n, t1, y1, t1[i]);
	}// end for

	// print out the spline results
	for (int j = 0; j < n; j++) {
		cout << j << " Spline: " << k[j] << endl;
	}// end for
	cout << endl;
	//zValue(n, t1, y1, z);
	system("pause");
}

double spline(int n, double t[], double y[], double x)
{
	int i;
	double spline1;
	for (i = n-1; i >= 1; i--) {
		if (x - t[i] >= 0) {
			cout << "X - t[i] is greater than or equal to zero. Exiting loop." << endl;
			break;
		}// end if
	}// end for
	
	//cout << "i" << setw(10) << "x" << setw(15) << "x - t[i]" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	//cout << i << setw(10) << x << setw(10) << x - t[i] << setw(10) << endl;
	
	cout << "Function: " << y[i] << " + (x - " << t[i] << ") * " << y[i + 1] - y[i] 
		 << "/" << t[i + 1] - t[i] << endl;
	cout << endl;
	//cout << "Spline:  " << y[i] <<  << endl;
	return ( y[i] + (x-t[i]) * ( (y[i+1] - y[i])/(t[i+1] - t[i]) ) ) ;
}

// computes z values, just a check 
double zValue(int n, double t[], double y[], double z[])
{
	int i;
	z[0] = 0;
	for (i = 0; i < n; i++) {
		z[i + 1] = -z[i] + 2 * ((y[i+1] - y[i])/(t[i+1] - t[i]));
		cout << "z[" << i <<"]: "<< z[i] << endl;
	}// end for

	return 0;
}