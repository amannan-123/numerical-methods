#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void ApplyBisection()
{

#define f(x) cos(x) - x *exp(x)

	/* Declaring required variables */
	float x0, x1, x, f0, f1, f, e;
	int step = 1, N;

	/* Setting precision and writing floating point values in fixed-point notation. */
	cout << setprecision(6) << fixed;

	/* Inputs */
up:
	cout << "Enter first guess: ";
	cin >> x0;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter error tolerance: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	/* Calculating Functional Value */
	f0 = f(x0);
	f1 = f(x1);

	/* Checking whether given guesses brackets the root or not. */
	if (f0 * f1 > 0.0)
	{
		cout << "Incorrect Initial Guesses." << endl;
		goto up;
	}
	/* Implementing Bisection Method */
	cout << "\n****************" << endl;
	cout << "Bisection Method" << endl;
	cout << "****************" << endl;
	do
	{
		/* Bisecting Interval */
		x = (x0 + x1) / 2;
		f = f(x);

		cout << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

		if (f0 * f < 0)
		{
			x1 = x;
		}
		else
		{
			x0 = x;
		}
		step = step + 1;

		if (step > N)
		{
			cout << "\nLimit Reached.\n";
			return;
		}
	} while (fabs(f) > e);

	cout << "\nRoot is : " << x << endl;
	cout << "Number of Iterations: " << step - 1 << endl;
}

void ApplySecant()
{

#define f(x) x *x *x - 2 * x - 5

	float x0, x1, x2, f0, f1, f2, e;
	int step = 1, N;

	/* Setting precision and writing floating point values in fixed-point notation. */
	cout << setprecision(6) << fixed;

	/* Inputs */
	cout << "Enter first guess: ";
	cin >> x0;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter error tolerance: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	/* Implementing Secant Method */
	cout << "\n**************" << endl;
	cout << "Secant Method" << endl;
	cout << "**************" << endl;
	do
	{
		f0 = f(x0);
		f1 = f(x1);
		if (f0 == f1)
		{
			cout << "Mathematical Error.";
			return;
		}

		x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
		f2 = f(x2);

		cout << step << ":\t x2 = " << setw(10) << x2 << " and f(x2) = " << setw(10) << f(x2) << endl;

		x0 = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;

		step = step + 1;

		if (step > N)
		{
			cout << "\nLimit Reached.\n";
			return;
		}
	} while (fabs(f2) > e);

	cout << "\nRoot is: " << x2 << endl;
	cout << "Number of Iterations: " << step - 1 << endl;
}

void ApplyRegulaFalsi()
{

#define f(x) cos(x) - x *exp(x)

	/* Declaring required variables */
	float x0, x1, x, f0, f1, f, e;
	int step = 1,N;

	/* Setting precision and writing floating point values in fixed-point notation. */
	cout << setprecision(6) << fixed;

/* Inputs */
up:
	cout << "Enter first guess: ";
	cin >> x0;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter tolerable error: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	/* Calculating Functional Value */
	f0 = f(x0);
	f1 = f(x1);

	/* Checking whether given guesses brackets the root or not. */
	if (f0 * f1 > 0.0)
	{
		cout << "Incorrect Initial Guesses." << endl;
		goto up;
	}
	/* Implementing False Position Method */
	cout << endl
		 << "*********************" << endl;
	cout << "False Position Method" << endl;
	cout << "*********************" << endl;
	do
	{
		/* Applying False Position Method */
		/* x is next approximated root using False Position method */
		x = x0 - (x0 - x1) * f0 / (f0 - f1);
		f = f(x);

		cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

		if (f0 * f < 0)
		{
			x1 = x;
			f1 = f;
		}
		else
		{
			x0 = x;
			f0 = f;
		}
		step = step + 1;
		if (step > N)
		{
			cout << "\nLimit Reached.\n";
			return;
		}
	} while (fabs(f) > e);

	cout << endl
		 << "Root is: " << x << endl;
}

void ApplyNewtonRaphson()
{
	/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define f(x) 3 * x - cos(x) - 1

/* Defining derivative of g(x).
   As you change f(x), change this function also. */
#define g(x) 3 + sin(x)

	float x0, x1, f0, f1, g0, e;
	int step = 1, N;

	/* Setting precision and writing floating point values in fixed-point notation. */
	cout << setprecision(6) << fixed;

	/* Inputs */
	cout << "Enter initial guess: ";
	cin >> x0;
	cout << "Enter tolerable error: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	/* Implementing Newton Raphson Method */
	cout << endl
		 << "*********************" << endl;
	cout << "Newton Raphson Method" << endl;
	cout << "*********************" << endl;
	do
	{
		g0 = g(x0);
		f0 = f(x0);
		if (g0 == 0.0)
		{
			cout << "Mathematical Error.";
			exit(0);
		}

		x1 = x0 - f0 / g0;

		cout << "Iteration-" << step << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f(x1) << endl;
		x0 = x1;

		step = step + 1;

		if (step > N)
		{
			cout << "Not Convergent.";
			exit(0);
		}

		f1 = f(x1);

	} while (fabs(f1) > e);

	cout << endl
		 << "Root is: " << x1;
}
