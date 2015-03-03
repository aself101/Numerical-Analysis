#include <iostream>
#include <cmath>
using namespace std;


double qFP(double e, double f, double g);
double qFN(double e, double f, double g);

int main()
{
	double a(1), b(pow(10,8)), c(1);
	double c1 = b;

	cout << "First quadratic formula (c = 1) +: " << qFP(a,b,c) << endl;
	cout << "First quadratic formula (c = 1) -: " << qFN(a,b,c) << endl;
	cout << "Second quadratic formula (c = 10^8) +: " << qFP(a, b, c1) << endl;
	cout << "Second quadratic formula (c = 10^8) -: " << qFN(a, b, c1) << endl;
	

	system("pause");
	return 0;
}

// -b + sqrt(b^2 - 4ac) / 2a
double qFP(double e, double f, double g)
{
	double quad1 = (-f + sqrt( pow(f, 2) - 4*e*g )) / (2 * e);
	return quad1;
}
// -b - sqrt(b^2 - 4ac) / 2a
double qFN(double e, double f, double g)
{
	double quad2 = (-f - sqrt(pow(f, 2) - 4 * e*g) ) / (2 * e);
	return quad2;
}
