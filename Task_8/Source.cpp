#include <iostream>

using namespace std;

double f(double x)
{
	return 4 * x - 7 * sin(x);
}

double AverageMethod(double a, double b, int n)
{
	double s = (f(a) + f(b)) / 2;
	double h = (b - a) / n;
	double I;

	for (int i = 1; i <= n - 1; i++)
	{
		s += f(a + i * h);
	}
	I = h * s;

	return I;
}

double SpecifiedAccuracyMethod(double a, double b, double eps)
{
	double I = eps + 1, I1 = 0;
	for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += f(a + h * i);
			sum2 += f(a + h * (i + 1));
		}
		sum = f(a) + 4 * sum4 + 2 * sum2 - f(b);
		I = I1;
		I1 = (h / 3) * sum;
	}

	return I1;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	double a, b, eps = 0.00001;
	int n;

	cout << "Заданная точность: " << eps << endl;
	cout << "Введите a b n" << endl;
	cin >> a >> b >> n;


	cout << "Метод средних: " << AverageMethod(a, b, n) << endl;
	cout << "Метод с заданной точностью: " << SpecifiedAccuracyMethod(a, b, 0.00001) << endl;

	system("pause");

	return 0;
}