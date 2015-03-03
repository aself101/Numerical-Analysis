/*****************************************
Alexander Self
CS 407: Numerical Analysis
1/16/2014
-This program demonstrates all the possible
name combinations of Russian mathematician 
P.L. Chebyshev.
*****************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first[] = {"Cheb","Ceb","Tscheb","Tcheb"};
	string mid[] = {"i", "y"};
	string last[] = {"shev","schef","cev","cheff","scheff"};
	int count = 0;

	for (int i = 0; i < 4; i++) {	// 4 possibilities
		for (int j = 0; j < 2; j++) {	// 2 possibilities
			for (int k = 0; k < 5; k++){	// 5 possibilities
				cout << "P.L. " << first[i] << mid[j] << last[k] << endl;
				count++;
			}//end third for
		}//end second for
	}// end first for
	cout << "Number of possible names: " << count << endl;

	system("pause");
	return 0;
}