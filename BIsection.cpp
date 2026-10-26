#include <iostream>
using namespace std;

double f(double x)
{
    return x*x*x - x - 1;
}

int main()
{
    double a, b, c, e;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter tolerance: ";
    cin >> e;

    // Check root exists or not
    if (f(a) * f(b) > 0)
    {
        cout << "Invalid interval" << endl;
        return 0;
    }

    // Bisection Method
    while ((b - a) > e)
    {
        c = (a + b) / 2;

        if (f(c) == 0)
        {
            break;
        }

        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    c = (a + b) / 2;

    cout << "Approximate root = " << c << endl;

    return 0;
}
