#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void ApplyEuler()
{
	/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
#define f(x, y) x + y

	float x0, y0, xn, h, yn, slope;
	int i, n;

	cout << "Enter Initial Condition" << endl;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "Enter calculation point xn = ";
	cin >> xn;
	cout << "Enter number of steps: ";
	cin >> n;

	/* Calculating step size (h) */
	h = (xn - x0) / n;

	/* Euler's Method */
	cout << "\nx0\ty0\tslope\tyn\n";
	cout << "------------------------------\n";

	for (i = 0; i < n; i++)
	{
		slope = f(x0, y0);
		yn = y0 + h * slope;
		cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
		y0 = yn;
		x0 = x0 + h;
	}

	/* Displaying result */
	cout << "\nValue of y at x = " << xn << " is " << yn;
}

void ApplyRungeKutta()
{
	/* Defining ordinary differential equation to be solved */
#define f(x, y) (y * y - x * x) / (y * y + x * x)

	float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
	int i, n;

	cout << "Enter Initial Condition" << endl;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "Enter calculation point xn = ";
	cin >> xn;
	cout << "Enter number of steps: ";
	cin >> n;

	/* Calculating step size (h) */
	h = (xn - x0) / n;

	/* Runge Kutta Method */
	cout << "\nx0\ty0\tyn\n";
	cout << "------------------\n";
	for (i = 0; i < n; i++)
	{
		k1 = h * (f(x0, y0));
		k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
		k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
		k4 = h * (f((x0 + h), (y0 + k3)));
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		yn = y0 + k;
		cout << x0 << "\t" << y0 << "\t" << yn << endl;
		x0 = x0 + h;
		y0 = yn;
	}

	/* Displaying result */
	cout << "\nValue of y at x = " << xn << " is " << yn;
}

void ApplyPicard()
{
	// required macros defined below:
#define Y1(x) (1 + (x) + pow(x, 2) / 2)
#define Y2(x) (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8)
#define Y3(x) (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8 + pow(x, 5) / 15 + pow(x, 6) / 48)

	double start_value = 0, end_value = 3,
		   allowed_error = 0.4, temp;
	double y1[30], y2[30], y3[30];
	int count;

	for (temp = start_value, count = 0;
		 temp <= end_value;
		 temp = temp + allowed_error, count++)
	{

		y1[count] = Y1(temp);
		y2[count] = Y2(temp);
		y3[count] = Y3(temp);
	}
	cout << setprecision(4) << fixed;
	cout << "\nX\n";
	for (temp = start_value;
		 temp <= end_value;
		 temp += allowed_error)
	{
		cout << temp<<"\t";
	}

	cout << "\n\nY(1)\n";
	for (temp = start_value, count = 0;
		 temp <= end_value;
		 temp = temp + allowed_error, count++)
	{
		cout << y1[count]<<"\t";
	}

	cout << "\n\nY(2)\n";
	for (temp = start_value, count = 0;
		 temp <= end_value;
		 temp = temp + allowed_error, count++)
	{
		cout << y2[count]<<"\t";
	}

	cout << "\n\nY(3)\n";
	for (temp = start_value, count = 0;
		 temp <= end_value;
		 temp = temp + allowed_error, count++)
	{
		cout << y3[count]<<"\t";
	}
	cout<<endl;
}