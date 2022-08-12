#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void NewtonForwardDerivation()
{
	double XX, x[10], f[10][10], p[10], diff[10][10], P1, delF[10], f1, f2;
	int n;
	double h, s;

	cout << "Enter the number of values: ";
	cin >> n;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "ENter X[" << i << "] : ";
		cin >> x[i];
	}
	cout << endl;

	for (int j = 0; j < n; j++)
	{
		cout << "ENter F[" << j << "] : ";
		cin >> f[0][j];
	}
	cout << endl;

	cout << "Enter X for which the value is to be found: ";
	cin >> XX;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]);
			if (f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] > -0.0000009 && f[i][j] < 0)
			{
				f[i][j] = 0;
			}
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
	for (int i = 1; i < 10; i++)
	{
		if (i < n)
			delF[i] = f[i][0];
		else
			delF[i] = 0;
	}
	f1 = 1 / h * (delF[1] + 1 / 2.0 * (2 * s - 1) * delF[2] + 1 / (6.0) * (3 * s * s - 6 * s + 2) * delF[3] + 1 / (24.0) * (4 * s * s * s - 18 * s * s + 22 * s - 6) * delF[4]);
	f2 = 1 / (h * h) * (delF[2] + 1 / 6.0 * (6 * s - 6) * delF[3] + 1 / 24.0 * (12 * s * s - 36 * s + 22) * delF[4]);

	cout << endl
		 << "The value of f1 :" << f1;
	cout << endl
		 << "The value of f2 :" << f2;
	cout << endl
		 << endl;
}

void NewtonBackwardDerivation()
{
	double XX, x[10], f[10][10], p[10], diff[10][10], P1, delF[10], f1, f2;
	int n;
	double h, s;

	cout << "Enter the number of values: ";
	cin >> n;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "ENter X[" << i << "] : ";
		cin >> x[i];
	}
	cout << endl;

	for (int j = 0; j < n; j++)
	{
		cout << "ENter F[" << j << "] : ";
		cin >> f[0][j];
	}
	cout << endl;

	cout << "Enter X for which the value is to be found: ";
	cin >> XX;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]);
			if (f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] > -0.0000009 && f[i][j] < 0)
			{
				f[i][j] = 0;
			}
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
	cout << "h = " << h;
	s = (XX - x[n - 1]) / h;
	cout << "s = " << s;

	for (int i = 1; i < 10; i++)
	{
		if (i < n)
			delF[i] = f[i][n - i - 1];
		else
			delF[i] = 0;
	}
	for (int i = 1; i < 10; i++)
	{
		cout << delF[i];
	}

	f1 = 1 / h * (delF[1] + 1 / 2.0 * (2 * s + 1) * delF[2] + 1 / (6.0) * (3 * s * s + 6 * s + 2) * delF[3] + 1 / (24.0) * (4 * s * s * s + 18 * s * s + 22 * s + 6) * delF[4]);
	f2 = 1 / (h * h) * (delF[2] + 1 / 6.0 * (6 * s + 6) * delF[3] + 1 / 24.0 * (12 * s * s + 36 * s + 22) * delF[4]);

	cout << endl
		 << "The value of f1 :" << f1;
	cout << endl
		 << "The value of f2 :" << f2;
	cout << endl
		 << endl;
}