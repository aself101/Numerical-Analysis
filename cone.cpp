/******************************************************
Alexander Self
CS 407: Numerical Analysis
4/25/14
-- This program computes the volume of a cone using a 
random number generator
*******************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <fstream>
using namespace std;
const int n = 5000;

void coneVolume();
void random(double y[][3]);
void intro();
void time();

void main(void)
{
	intro();
	coneVolume();
	//for (int i = 0; i < 5000; i++)  To get an average
	

	system("pause");
}

void coneVolume()
{
	int i, m(0), iprt(1000);
	double vol, x, y, z;
	double y1[n][3];
	double avg[5];
	ofstream out;
	
	out.open("data.txt",std::fstream::app);
	// Fill up 2d array
	random(y1);

	cout << "i" << setw(15) << "Volume" << endl;
	cout << "---------------------------------------" << endl;
	
	for (i = 1; i <= n; i++) {
		x = 2 * y1[i][1] - 1;		
		y = 2 * y1[i][2] - 1;
		z = 2 * y1[i][3];
		if (x * x + y * y <= z * z && x * x + y * y <= z * (2 - z)) 
			m++;
		if (i % iprt == 0) {
			vol = 8 * static_cast<double>(m) / static_cast<double>(i);
			cout << i << setw(10) << vol << endl;
			out << vol << endl;
		}// end if
	}// end for
	out.close();
}

void random(double y[][3])
{
	int seed = time(NULL);
	int i, a;

	int k = 16807, j = 2147483647;

	for (i = 0; i < n; i++){
		for (a = 0; a < 3; a++) {
			seed = (k * seed) % j;
			y[i][a] = abs((static_cast<double>(seed) / static_cast<double>(j)));
		}
	}
}

void intro()
{
	cout << "Random Number Generator to approximate a cone!" << endl << endl;
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