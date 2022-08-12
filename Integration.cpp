#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void ApplyTrapezoidal()
{
	/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

	float lower, upper, integration = 0.0, stepSize, k;
	int i, subInterval;

	/* Input */
	cout << "Enter lower limit of integration: ";
	cin >> lower;
	cout << "Enter upper limit of integration: ";
	cin >> upper;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	/* Calculation */

	/* Finding step size */
	stepSize = (upper - lower) / subInterval;

	/* Finding Integration Value */
	integration = f(lower) + f(upper);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lower + i * stepSize;
		integration = integration + 2 * (f(k));
	}

	integration = integration * stepSize / 2;

	cout << endl
		 << "Required value of integration is: " << integration;
}

void ApplySimpson13()
{
	/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

	float lower, upper, integration = 0.0, stepSize, k;
	int i, subInterval;

	/* Input */
	cout << "Enter lower limit of integration: ";
	cin >> lower;
	cout << "Enter upper limit of integration: ";
	cin >> upper;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	/* Calculation */

	/* Finding step size */
	stepSize = (upper - lower) / subInterval;

	/* Finding Integration Value */
	integration = f(lower) + f(upper);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lower + i * stepSize;

		if (i % 2 == 0)
		{
			integration = integration + 2 * (f(k));
		}
		else
		{
			integration = integration + 4 * (f(k));
		}
	}

	integration = integration * stepSize / 3;

	cout << endl
		 << "Required value of integration is: " << integration;
}

void ApplySimpson38()
{
	/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

	float lower, upper, integration = 0.0, stepSize, k;
	int i, subInterval;

	/* Input */
	cout << "Enter lower limit of integration: ";
	cin >> lower;
	cout << "Enter upper limit of integration: ";
	cin >> upper;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	/* Calculation */

	/* Finding step size */
	stepSize = (upper - lower) / subInterval;

	/* Finding Integration Value */
	integration = f(lower) + f(upper);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lower + i * stepSize;

		if (i % 3 == 0)
		{
			integration = integration + 2 * (f(k));
		}
		else
		{
			integration = integration + 3 * (f(k));
		}
	}

	integration = integration * stepSize * 3.0 / 8.0;

	cout << endl
		 << "Required value of integration is: " << integration;
}

void BooleRule()
{
#define f(x) 1 / (1 + x)

	float a, b;
	int n;
	/* Input */
	cout << "Enter lower limit of integration: ";
	cin >> a;
	cout << "Enter upper limit of integration: ";
	cin >> b;
	cout << "Enter number of sub intervals: ";
	cin >> n;

	// Computing the step size
	int h = ((b - a) / n);

	float bl = ((7 * f(a) +
				 32 * f(a + h) +
				 12 * f(a + 2 * h) +
				 32 * f(a + 3 * h) +
				 7 * f(a + 4 * h)) *
				2 * h / 45);

	cout << endl
		 << "Required value of integration is: " << bl;
}

void WeddleRule()
{
#define k(x) 1 / (pow(x, 2))

	float a, b;
	int n;
	/* Input */
	cout << "Enter lower limit of integration: ";
	cin >> a;
	cout << "Enter upper limit of integration: ";
	cin >> b;
	cout << "Enter number of sub intervals: ";
	cin >> n;

	// Computing the step size
	float h = (b - a) / n;
	
	if (n % 6 == 0)
	{
		float s = ((3 * h / 10) * (k(a) + k(a + 2 * h) + 5 * k(a + h) + 6 * k(a + 3 * h) + k(a + 4 * h) + 5 * k(a + 5 * h) + k(a + 6 * h)));

		cout << "Value of integral is " << s << endl;
	}
	else
	{
		cout << "Sorry ! Weddle rule is not applicable";
	}
}
