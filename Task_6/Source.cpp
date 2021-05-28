#include <iostream>
#include <math.h>

using namespace std;

const double eps = 0.0001;

inline double sq(double x)
{
	return 7 * sin(x) / 4;
}

double sq1(double x)
{
	return 4 * x - 7 * sin(x);
}

double SimpleIterationMethod(double a, double b)
{
	double x0 = a, x1;

	for (;;)
	{
		x1 = sq(x0);
		if (fabs(x1 - x0) < eps)
			break;
		x0 = x1;
	}

	return x1;
}

int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "RUS");

	int a = -2, b = 2;
	double h = 0.01;
	int i = 1;

	for (double x = a; x <= b; x += h)
	{
		if (sq1(x) * sq1(x + h) < 0)
		{
			double Res = SimpleIterationMethod(x + h, b);
			cout << "Корень " << i << " : ";
			if (Res > 0 && Res < 0.000001)
			{
				cout << "0" << endl;
			}
			else
			{
				cout << SimpleIterationMethod(x + h, b) << endl;
			}
			i++;
		}
	}


	system("pause");
}