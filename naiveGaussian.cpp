/*****************************************************
Alexander Self
CS 407: Numerical Analysis
2/3/14

//This program provides the Naive Gaussian algorithm
for processing systems of linear equations.
******************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

void gaussian(double x[], double b[], double a[][3]);

int main()
{
	//double a1[3][3];			// 2 rows, 3 columns
	double x1[4] = {};	 // place holder
	double b1[4] = { 0.7381, 0.9327 };		// right hand side of system of eq.
	double b2[4] = {1,2};
	double a1[3][3] = { 0,1,1,
						1,1,2 };			// 2 rows, 3 columns
	double a2[3][3] = { 0.1036, 0.2122, 0.7381,
						0.2081, 0.4247, 0.9327 };			// 2 rows, 3 columns

	
	cout << "Original system: " << endl;
	cout << " " << a2[0][0] << " " << a2[0][1] << " " << a2[0][2] << endl;
	cout << " " << a2[1][0] << " " << a2[1][1] << " " << a2[1][2] << endl;
	gaussian(x1, b1, a2);

	cout << "************************************" << endl;

	cout << "Original system: " << endl;
	cout << " " << a1[0][0] << " " << a1[0][1] << " " << a1[0][2] << endl;
	cout << " " << a1[1][0] << " " << a1[1][1] << " " << a1[1][2] << endl;
	gaussian(x1, b2, a1);


	system("pause");
	return 0;
}

void gaussian(double x[], double b[], double a[][3])
{
	double sum(0), xmult, x2, x1, temp1,temp2, temp3;
	int i, j(0), k, n(3);
	vector<double> temp;

	/***** Forward elimination *****/
	for (k = 0; k <= n-1; k++) {
		for (i = k+1; i < n; i++) {
			xmult = a[i][k] / a[k][k];	// location of 0, stored here
			a[i][k] = 0.0;
			for (j = k+1; j < n; j++) {
				a[i][j] = a[i][j] - (xmult*a[k][j]);	// coefficient array
				temp.push_back(a[i][j]);
			}// end 3rd for
			b[i] = b[i] - (xmult * b[k]);				// right hand side of systems equation
		}// end 2nd for
	}// end 1st for
	/*********************************************************************/
	// Ran into some issues and could not get the pseudocode to work,
	// so I hard coded in a basic algorithm that produces results for a 
	// 2x3 matrix
	temp1 = temp[0];	// save to get x2
	temp2 = temp[1];
	x2 = temp2 / temp1;		// var x2 stored
	cout << "New System: " << endl;
	cout << " " << a[0][0] << " " << a[0][1] << " " << a[0][2] << endl;
	cout << " " << a[1][0] << " " << a[1][1] << " " << a[1][2] << endl;
	x[n] = b[n] / a[n][n];		// store the solution in x[n]
//	cout << "x[n]: " << x[n] << endl;
	x[0] = x2;

	temp3 = a[0][2] - (a[0][1] * x2);
	//cout << "temp3: " << temp3 << endl;

	x1 = temp3 / a[0][0];
	
	/********************************************************************/
	//cout << "x1: " << x1 << endl;
	/***** Backward elimination *****/
	for (i = n - 1; i > 1; i--) {
		sum = b[i];
		for (j = i + 1; j < n; j++) {
			sum = sum - (a[i][j] * x[j]);
			//cout << "Sum: " << sum << endl;
		}// end inner for
		x[i] = sum / a[i][i];
	}// end outer for

	// Solved System of Linear Equation
	cout << "\nResults: " << endl;
	cout << "x1: " << x1 << " x2: " << x2 << endl;
	// Original System
	/*cout << "-- Original System --" << endl;
	cout << "a: " << a[0][0] << " " << a[0][1] << " " <<a[0][2] << endl;
	cout << "   " << a[1][0] << " " << a[1][1] << " " << a[1][2] << endl;
	*/

}

