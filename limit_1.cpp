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


// Ultimately the program needs to cease sooner before it explodes and the error becomes the derivative
int main()
{

	int i, iMin(0), n(50);
	double error, y, x(0.5), h(1.0), eMin(0.0);

	cout << "i" << setw(15) << "h" << setw(15) << "y" << setw(20) <<  "error" << endl;
	cout << "-----------------------------------------------------------" << endl;
	
	for (int i = 1; i < n; i++) {
		h = (0.25) * h;
		y = (sin(x + h) - sin(x)) / h;	// Calculating the approximate derivative of sin(x)
		error = (cos(x) - y);			// Find the error
		cout << i << setw(22) << h << setw(17)  << y << setw(17) << error << endl;
		//cout << "eps: " << eps << endl;
		if (error < eMin) {
			eMin = error;					// Looking for the minimum error
			iMin = i;						// The minimum iteration where the error becomes becomes less than 0 
		}// end if
	}// end for

	cout << "iMax is: " << iMin << endl;
	cout << "eMax is: " << eMin << endl;
	system("pause");
	return 0;
}

