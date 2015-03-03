/*************************************************
Alexander Self
CS407: Numerical Analysis
4/21/14
-- This program creates a set of random numbers to
fit into a trapezoid
**************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

void random(vector<double> x, double y[]);
void randomTrap(vector<double> x, double y[]);
void intro();
void time();

const int n = 30000;

void main(void)
{
	vector<double> x;
	double y[n];
	x.resize(n);
	intro();
	randomTrap(x, y);

	system("pause");
}

void random(vector<double> x, double y[])
{
	int seed = time(NULL);
	int i, m;
	
	int k = 16807, j = 2147483647;
	m = x.size();
	for (i = 0; i < m; i++){
		seed = (k * seed) % j;
		x[i] = (static_cast<double>(seed) / static_cast<double>(j));
		y[i] = x[i];	
	}
}
// Function for random points to fill a trapezoid
void randomTrap(vector<double> x, double y[])
{
	ofstream out;
	out.open("data.txt");
	int i, j(0);
	double u, v;		
	double x1[n], y1[n];
	random(x, y);			
	// (1,3) (2,5) (4,3) (3,5)
	for (i = 0; i < n; i++) {
		u = (4) * y[i] + 1;
		v = (3) * y[i+1] + 3;
		// Force x and y values to be less than min/max points
		if ( ((v - 2 * u) < 1) && ((v + 2 * u) < 11) && (u < 4) && (u > 1) && (v > 3) && (v < 5)) {
			x1[i] = u;
			y1[i] = v;
			j++;
			out << x1[i] << "\t" << y1[i] << endl;
		}// end if
	}// end for
	out.close();
}// end randomTrap()

void intro()
{
	cout << "Random Number Generator to fill a Trapezoid" << endl << endl;
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


