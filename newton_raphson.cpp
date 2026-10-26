#include <iostream>
#include <cmath>
using namespace std;

// Function
double f(double x)
{
    return x*x - 3*x + 2;
}

// Derivative
double df(double x)
{
    return 2*x - 3;
}

int main()
{
    double x0, x1, e;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> e;

    while (true)
    {
        // Newton-Raphson formula
        x1 = x0 - f(x0) / df(x0);

        // Stopping condition
        if (fabs(x1 - x0) < e)
        {
            break;
        }

        // New value becomes old value
        x0 = x1;
    }

    cout << "Approximate root = " << x1 << endl;

    return 0;
}
