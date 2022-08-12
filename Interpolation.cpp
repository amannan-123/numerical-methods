#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void GaussForward()
{
	int n;
	int i, j;
	float nr, dr;
	float y = 0;
	float h;
	float p;
	float diff[20][20];
	float y1, y2, y3, y4;

	cout << "Enter the number of values: ";
	cin >> n;

	float *ax = new float(n);
	float *ay = new float(n);

	for (i = 0; i < n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> ax[i] >> ay[i];
	}

	float x;
	cout << "Enter X for which the value is to be found: ";
	cin >> x;

	h = ax[1] - ax[0];

	for (i = 0; i < n - 1; i++)
		diff[i][1] = ay[i + 1] - ay[i];

	for (j = 2; j <= 4; j++)
		for (i = 0; i < n - j; i++)
			diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

	i = floor(n / 2);

	p = (x - ax[i]) / h;

	y1 = p * diff[i][1];
	y2 = p * (p - 1) * diff[i - 1][2] / 2;
	y3 = (p + 1) * p * (p - 1) * diff[i - 1][3] / 6;
	y4 = (p + 1) * p * (p - 1) * (p - 2) * diff[i - 2][4] / 24;

	y = ay[i] + y1 + y2 + y3 + y4;

	cout << "\nThe value at x = " << x << " is " << y << endl;
}

void GaussBackward()
{
	int n;
	int i, j;
	float nr, dr;
	float y = 0;
	float h;
	float p;
	float diff[20][20];
	float y1, y2, y3, y4;

	cout << "Enter the number of values: ";
	cin >> n;

	float *ax = new float(n);
	float *ay = new float(n);

	for (i = 0; i < n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> ax[i] >> ay[i];
	}

	float x;
	cout << "Enter X for which the value is to be found: ";
	cin >> x;

	h = ax[1] - ax[0];

	for (i = 0; i < n - 1; i++)
		diff[i][1] = ay[i + 1] - ay[i];

	for (j = 2; j <= 4; j++)
		for (i = 0; i < n - j; i++)
			diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

	i = floor(n / 2);

	p = (x - ax[i]) / h;

	y1 = p * diff[i - 1][1];
	y2 = p * (p + 1) * diff[i - 1][2] / 2;
	y3 = (p - 1) * p * (p + 1) * diff[i - 2][3] / 6;
	y4 = (p - 1) * p * (p + 1) * (p + 2) * diff[i - 2][4] / 24;

	y = ay[i] + y1 + y2 + y3 + y4;

	cout << "\nThe value at x = " << x << " is " << y << endl;
}

void ApplyLagrange()
{
	float xp, yp = 0, p;
	int i, j, n;

	/* Input Section */
	cout << "Enter the number of values: ";
	cin >> n;

	float *x = new float(n);
	float *y = new float(n);

	for (i = 1; i <= n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> x[i] >> y[i];
	}
	cout << "Enter X for which the value is to be found: ";
	cin >> xp;

	/* Implementing Lagrange Interpolation */
	for (i = 1; i <= n; i++)
	{
		p = 1;
		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				p = p * (xp - x[j]) / (x[i] - x[j]);
			}
		}
		yp = yp + p * y[i];
	}
	cout << "\nThe value at x = " << xp << " is " << yp << endl;
}

void NewtonForward()
{

	double XX, x[10], f[10][10], p[10], diff[5][5], P1;
	int n;
	double h, s;

	cout << "Enter the number of values: ";
	cin >> n;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> x[i] >> f[0][i];
	}
	cout << endl;

	cout << "Enter X for which the value is to be found: ";
	cin >> XX;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]);
		}
	}
	cout << endl;
	cout << "Sn\tXi\tf(Xi)\t";
	for (int i = 0; i < n - 1; i++)
	{
		cout << i + 1 << " diff\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "\t" << x[i] << "\t";
		for (int j = 0; j < n - i; j++)
		{
			cout << f[j][i] << "\t";
		}
		cout << endl;
	}

	h = x[1] - x[0];
	s = (XX - x[0]) / h;

	P1 = f[0][0];
	for (int i = 1; i < n; i++)
	{
		double k = s;
		for (int j = 1; j < i; j++)
		{
			k *= (s - j) * 1 / (j + 1);
		}
		k *= f[i][0];
		P1 += k;
	}
	cout << "\nThe value at x = " << XX << " is " << P1 << endl;
}

void NewtonBackward()
{

	double XX, x[10], f[10][10], p[10], diff[5][5], P1;
	int n;
	double h, s;

	cout << "Enter the number of points: ";
	cin >> n;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> x[i] >> f[0][i];
	}
	cout << endl;

	cout << "Enter X for which the value is to be found: ";
	cin >> XX;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]);
		}
	}
	cout << endl;
	cout << "Sn\tXi\tf(Xi)\t";
	for (int i = 0; i < n - 1; i++)
	{
		cout << i + 1 << " diff\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "\t" << x[i] << "\t";
		for (int j = 0; j < n - i; j++)
		{
			cout << f[j][i] << "\t";
		}
		cout << endl;
	}

	h = x[1] - x[0];
	s = (XX - x[n - 1]) / h;

	P1 = f[0][n - 1];
	for (int i = 1; i < n; i++)
	{
		double k = s;
		for (int j = 1; j < i; j++)
		{
			k *= (s + j) * 1 / (j + 1);
		}
		k *= f[i][n - i - 1];
		P1 += k;
	}
	cout << "\nThe value at x = " << XX << " is " << P1 << endl;
}

void ApplyStirling()
{
	int n;
	cout << "Enter the number of points: ";
	cin >> n;

	float *x = new float[n];
	float *fx = new float[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the (space separated) x and f(x) values: ";
		cin >> x[i] >> fx[i];
	}

	float x1;
	cout << "Enter X for which the value is to be found: ";
	cin >> x1;

	float h, a, u, y1 = 0, N1 = 1, d = 1,
				   N2 = 1, d2 = 1, temp1 = 1, temp2 = 1,
				   k = 1, l = 1;

	float **delta = new float *[n];
	for (int i = 0; i < n; i++)
	{
		delta[i] = new float[n];
	}

	int i, j, s;
	h = x[1] - x[0];
	s = floor(n / 2);
	a = x[s];
	u = (x1 - a) / h;

	// Preparing the forward difference
	// table
	for (i = 0; i < n - 1; ++i)
	{
		delta[i][0] = fx[i + 1] - fx[i];
	}
	for (i = 1; i < n - 1; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			delta[j][i] = delta[j + 1][i - 1] - delta[j][i - 1];
		}
	}

	// Calculating f(x) using the Stirling
	// formula
	y1 = fx[s];

	for (i = 1; i <= n - 1; ++i)
	{
		if (i % 2 != 0)
		{
			if (k != 2)
			{
				temp1 *= (pow(u, k) -
						  pow((k - 1), 2));
			}
			else
			{
				temp1 *= (pow(u, 2) -
						  pow((k - 1), 2));
			}
			++k;
			d *= i;
			s = floor((n - i) / 2);
			y1 += (temp1 / (2 * d)) *
				  (delta[s][i - 1] +
				   delta[s - 1][i - 1]);
		}
		else
		{
			temp2 *= (pow(u, 2) -
					  pow((l - 1), 2));
			++l;
			d *= i;
			s = floor((n - i) / 2);
			y1 += (temp2 / (d)) *
				  (delta[s][i - 1]);
		}
	}

	cout << "\nThe value at x = " << x1 << " is " << y1 << endl;
}