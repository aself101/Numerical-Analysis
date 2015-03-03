/***************************************************
Alexander Self
CS 407: Numerical Analysis
2/5/14
// This program is designed to complete Gaussian
elimination on a system of linear equations using
scaled partial pivoting.
****************************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

// Main Gaussian elimination with scaled partial pivoting 
void gaussian(double (&a)[4][4], double (&l)[5], int n);
// Solves the final equation with the back elimination
void solve(double a[][4], double l[],
	double b[], double x[] ,int n);
// Prints 2d matrix
void printMatrix(vector<vector<double>> a);

int main()
{
	int n(4);				// number of equations to solve
	// Main matrix
	double a1[4][4] = { { 3, -13, 9, 3 }, { -6, 4, 1, -18 },
	{ 6, -2, 2, 4 }, { 12, -8, 6, 10 } };
	/*vector<vector<double>> a = { { 3, -13, 9, 3 }, { -6, 4, 1, -18 },
	{ 6, -2, 2, 4 }, { 12, -8, 6, 10 } };
	vector<vector<double>> a1 = { { 1, -1, 2 }, { -2, 1, -1 }, { 4, -1, 2 } };
	vector<double> b1 = { -2, 2, -1 };*/
	double b[5] = { -19, -34, 16, 26 };	// Ax = b
	double l[5];	// index vector
	//vector<double> x;
	double x[5];
	gaussian(a1, l,n);
	solve(a1, l, b, x, n);
	system("pause");
	return 0;
}
/*
void gaussian(vector<vector<double>> a, vector<double> l,
	vector<double> b, int n)*/
// Main part of selecting pivot rows and ratios to reduce matrix
void gaussian(double (&a)[4][4], double (&l)[5], int n)
{
	int i, j, k;
	double r, xmult;
	double rmax, smax;				// max for scale vector and index vector
	int tempi, tempk;
	double s[4];
	double x[5];
	
	// Finds the pivot row
	for (i = 0; i < n; i++) {
		l[i] = i;					// fills up index with 1-n
		smax = 0.0;					// Scaler max is zero
		for (j = 0; j < n; j++)
			smax = max(smax, abs(a[i][j]));		// take the maximum value from pivot column
		s[i] = smax;						// set the scale vector equal to the pivot column
	}// end 1st fo

	// finds the ratio
	for (k = 1; k < n; k++) {
		rmax = 0.0;							// set max ratio to zero
		for (i = k; i < n; i++) {
			tempi = l[i];
			r = abs(a[tempi][k] / s[tempi]);		// find the ratios to set rmax
			//cout << "ratios: " << r << endl;
			if (r > rmax) {
				rmax = r;					// max ratio found!
				//cout << "rmax: " << rmax << endl;
				j = i;
			}// end if
		}//end 2nd for

		tempk = l[j];
		l[j] = l[k];
		l[k] = tempk;

		for (i = k + 1; i < n; i++) {
			tempi = l[i];

			xmult = (a[tempi][k] / a[tempk][k]);
			a[tempi][k] = xmult;
			for (j = k + 1; j < n; j++) {
				a[tempi][j] -= (xmult * a[tempk][j]);
			}// end 4th for
		}// end 3rd for
	}// end 1st for
	//solve(a, l, b, x, n);
}
// Solves the matrix
void solve(double a[4][4], double l[],
	double b[], double x[], int n)
{
	int i, j, k;
	int tempi, tempk, tempn;
	double sum;
	for (k = 1; k < n; k++) {
		tempk = l[k];
		for (i = k + 1; i < n; i++) {
			tempi = l[i];
			b[tempi] -= (a[tempi][k] * b[tempk]);
		}// end 2nd for
	}// end first for
	tempn = l[n];
	cout << "n: " << n << endl;
	x[tempn] = b[tempn] / a[tempn][n-1];

	
	for (i = n-1; i >= 1; i--) {
		
		tempi = l[i];
		
		sum = b[tempi];
		for (j = i + 1; j < n; j++) {
			sum -= (a[tempi][j] * x[j]);
		}// end 2nd for
		x[i] = sum / a[tempi][i];
	}// end 1st for


	cout << "x[0]: " << x[0] << " x[1]: " << x[1] << " x[2]: " << x[2] << " x[3]: " << x[3] << endl;
}

// prints maxtrix
void printMatrix(vector<vector<double>> a)
{
	for (auto& x : a) {
		for (auto& y : x) {
			cout << y << "\t";
		}// end 2nd for
		cout << endl;
	}// end 1st for
}





