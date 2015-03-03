/******************************************
Alexander Self
CS 407: Numerical Analysis
1/16/14
-This program demonstrates limit properties,
by imitating a basic limit operation of the 
equation: f(x+h)-f(x)/h
*******************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double eps = 0.5 * 0.000001;


// Ultimately the program needs to cease sooner before it explodes and the error becomes the derivative
int main()
{

	int i, iMin(0), n(50);
	double error, y, x(0.5), h(1.0), eMin(0.0);

	cout << "i" << setw(15) << "h" << setw(15) << "y" << setw(20) <<  "error" << endl;
	cout << "-----------------------------------------------------------" << endl;
	
	for (int i = 1; i < n; i++) {
		h = (0.25) * h;
		y = (sin(x + h) - sin(x-h)) / (2*h);	// Using the central difference forumla
		error = (cos(x) - y);			// Find the error
		cout << i << setw(22) << h << setw(17)  << y << setw(17) << error << endl;
		//cout << "eps: " << eps << endl;
		if (error < eps) {
			eMin = error;					// Looking for the minimum error
			iMin = i;						// The minimum iteration where the error becomes becomes less than 0 
			n = (6 - log(3.0)) / log(16.0);				// the value of n before the program goes bezerk and the error increases to its derivative, which stops the program
		}// end if
	}// end for

	cout << "iMax is: " << iMin << endl;
	cout << "eMax is: " << eMin << endl;
	system("pause");
	return 0;
}

