/****************************************************
Alexander Self
CS 407: Numerical Analysis
4/25/14
-- This program simulates a loaded dice scenario
****************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void random(double y[][24][2]);
void intro();
void time();

void main(void)
{
	intro();
	double x[2500][24][2];		//3d array for dice simulation, could not go beyond 3000, would overflow
	int i, j, i1, i2, m(0);
	int n(2500), iprt(100);
	double prob;
	random(x);

	cout << "{ i }" << setw(20) << "{ Probability }" << endl;
	cout << "-----------------------------------------------" << endl;
	for (i = 1; i < n; i++) {
		for (j = 1; j < 24; j++) {
			i1 = static_cast<int>(6 * x[i][j][1] + 1);		// Find chance of rolling a 6
			i2 = static_cast<int>(6 * x[i][j][2] + 1);
			if (i1 + i2 == 12) {
				m++;
				break;
			}// end if
		}// end for
		if (i % iprt == 0) {	// output every 100
			prob = static_cast<double>(m) / static_cast<double>(i);
			cout << i << setw(15) << prob * 100 << "%" << endl;
		}
	}// end for

	cout << "Actual probabilty of rolling a 12 is 1/36: " << (1.0 / 36.0) * 100 << "%" << endl;
	system("pause");
}

// Random function with 3d array
void random(double y[][24][2])
{
	int seed = time(NULL);
	int i, a, b, n(2500);

	int k = 16807, j = 2147483647;

	for (i = 0; i < n; i++) {
		for (a = 0; a < 24; a++) {
			for (b = 0; b < 2; b++) {
				seed = (k * seed) % j;
				y[i][a][b] = abs((static_cast<double>(seed) / static_cast<double>(j)));
			}// end 3rd for	
		}// end 2nd for
	}// end 1st for

}// end random()

void intro()
{
	cout << "Monte Carlo Simulation for probability of a dice throw!" << endl << endl;
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