#include <iostream>
#include <cmath>
using namespace std;

double epsilon(double &e);
int main()
{
	double epsil = 1.0;


	epsilon(epsil);


	cout << "Epsilon = " << epsil << endl;

	system("pause");
	return 0;
}



double epsilon(double &e)
{
	//double eps(0);

	while (1 + e > 1.0) {
		e = e / 2.0;
		cout << e << endl;
	}
	e = 2.0 * e;
	
	return e;
}