#include "RootFinders.cpp"
#include "LinearEquations.cpp"
#include "Interpolation.cpp"
#include "Derivation.cpp"
#include "Integration.cpp"
#include "ODE.cpp"

void RootFinding()
{
	cout << "\n************* Root Finding *************" << endl;
	cout << "1. False Position Method" << endl;
	cout << "2. Newton Raphson Method" << endl;
	cout << "3. Secant Method" << endl;
	cout << "4. Bisection Method" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		ApplyRegulaFalsi();
		break;
	case 2:
		ApplyNewtonRaphson();
		break;
	case 3:
		ApplySecant();
		break;
	case 4:
		ApplyBisection();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

void LinearEquations()
{
	cout << "\n************* Linear Equations *************" << endl;
	cout << "1. Jacobi Mathod" << endl;
	cout << "2. Gauss Seidel Method" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		ApplyJacobi();
		break;
	case 2:
		ApplyGaussSeidel();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

void Interpolation()
{
	cout << "\n************* Interpolation *************" << endl;
	cout << "1. Newton Forward" << endl;
	cout << "2. Newton Backward" << endl;
	cout << "3. Gauss Forward" << endl;
	cout << "4. Gauss Backward" << endl;
	cout << "5. Stirling's Method" << endl;
	cout << "6. Lagrange Method" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		NewtonForward();
		break;
	case 2:
		NewtonBackward();
		break;
	case 3:
		GaussForward();
		break;
	case 4:
		GaussBackward();
		break;
	case 5:
		ApplyStirling();
		break;
	case 6:
		ApplyLagrange();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

void Derivation()
{
	cout << "\n************* Derivation *************" << endl;
	cout << "1. Newton Forward" << endl;
	cout << "2. Newton Backward" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		NewtonForwardDerivation();
		break;
	case 2:
		NewtonBackwardDerivation();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

void Integration()
{
	cout << "\n************* Integration *************" << endl;
	cout << "1. Trapezoidal Rule" << endl;
	cout << "2. Simpson's 1/3 Rule" << endl;
	cout << "3. Simpson's 3/8 Rule" << endl;
	cout << "4. Boole Rule" << endl;
	cout << "5. Weddle Rule" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		ApplyTrapezoidal();
		break;
	case 2:
		ApplySimpson13();
		break;
	case 3:
		ApplySimpson38();
		break;
	case 4:
		BooleRule();
		break;
	case 5:
		WeddleRule();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

void ODE()
{
	cout << "\n************* ODE *************" << endl;
	cout << "1. Euler Method" << endl;
	cout << "2. Picard Method" << endl;
	cout << "3. Runge-Kutta Method" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		ApplyEuler();
		break;
	case 2:
		ApplyPicard();
		break;
	case 3:
		ApplyRungeKutta();
		break;
	case 0:
		break;
	default:
		cout << "Invalid Choice" << endl;
		break;
	}
}

int main()
{
	bool _exit = false;
	while (!_exit)
	{
		cout << "\n************* Numerical Methods *************" << endl;
		cout << "1. Root Finding" << endl;
		cout << "2. Linear Equations" << endl;
		cout << "3. Interpolation" << endl;
		cout << "4. Derivation" << endl;
		cout << "5. Integration" << endl;
		cout << "6. ODE" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			RootFinding();
			break;
		case 2:
			LinearEquations();
			break;
		case 3:
			Interpolation();
			break;
		case 4:
			Derivation();
			break;
		case 5:
			Integration();
			break;
		case 6:
			ODE();
			break;
		case 0:
			_exit = true;
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
		cout << endl;
	}

	cout << "\n";
	system("pause");
	return 0;
}