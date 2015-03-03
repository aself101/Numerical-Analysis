#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void pi(double a1, double b1, double c1, double d1, double e1, 
	double f1, double g1);

int main()
{
	double a(0.0), b(1.0), c, d(0.25), e(1.0), f(0.0), g(0.0);
	c = (1 / sqrt(2.0));

	pi(a, b, c, d, e, f, g);

	system("pause");
	return 0;
}


void pi(double a1, double b1, double c1, double d1, double e1,
	double f1, double g1)
{
	double pi = 3.14159265359;
	long double pi2 = 4.0 * atan(1.0);

	for (int k = 0; k < 5; k++) {
		a1 = b1;
		b1 = (b1 + c1) / 2;
		c1 = sqrt(c1*a1);
		d1 = d1 - e1*(pow((b1 - a1), 2));
		e1 = 2*e1;
		f1 = pow(b1, 2) / d1;
		g1 = pow((b1 + c1), 2) / (4 * d1);
		cout << k << " f: " << setprecision(12) << f1 << " |f-pi|: " << abs(f1 - pi)
			<< " g: " << setprecision(12) << g1 << " |g-pi|: " 
			<< abs(g1 - pi) << endl;
	}// end for

	cout << "4.0 * arctan(1.0): " << setprecision(12) << pi2 << endl;
}
