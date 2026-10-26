Bankers:(pos)

#include <iostream>
using namespace std;

int main()
{
    double num, temp, factor = 1, answer;
    int n, nextDigit;
    long long mainPart;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter significant digits: ";
    cin >> n;

    temp = num;

    // Make number between 1 and 10
    while (temp >= 10)
    {
        temp = temp / 10;
        factor = factor / 10;
    }

    while (temp < 1)
    {
        temp = temp * 10;
        factor = factor * 10;
    }

    // Move n significant digits before decimal
    for (int i = 1; i < n; i++)
    {
        temp = temp * 10;
        factor = factor * 10;
    }

    mainPart = (long long)temp;

    // Find next digit
    nextDigit = (int)(temp * 10) % 10;

    // Banker's rounding
    if (nextDigit < 5)
    {
        // no change
    }
    else if (nextDigit > 5)
    {
        mainPart++;
    }
    else
    {
        if (mainPart % 2 != 0)
        {
            mainPart++;
        }
    }

    answer = mainPart / factor;

    cout << "Rounded value = " << answer << endl;

    return 0;
}



Bankers: (Neg)

#include <iostream>
using namespace std;

int main()
{
    double num, temp, factor = 1, answer;
    int n, nextDigit;
    long long mainPart;
    bool negative = false;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter significant digits: ";
    cin >> n;

    // Check negative number
    if (num < 0)
    {
        negative = true;
        num = -num;
    }

    temp = num;

    // Make number between 1 and 10
    while (temp >= 10)
    {
        temp = temp / 10;
        factor = factor / 10;
    }

    while (temp < 1)
    {
        temp = temp * 10;
        factor = factor * 10;
    }

    // Move n significant digits
    for (int i = 1; i < n; i++)
    {
        temp = temp * 10;
        factor = factor * 10;
    }

    mainPart = (long long)temp;

    nextDigit = (int)(temp * 10) % 10;

    // Banker's rounding
    if (nextDigit < 5)
    {
        // no change
    }
    else if (nextDigit > 5)
    {
        mainPart++;
    }
    else
    {
        if (mainPart % 2 != 0)
        {
            mainPart++;
        }
    }

    answer = mainPart / factor;

    // Return negative sign
    if (negative == true)
    {
        answer = -answer;
    }

    cout << "Rounded value = " << answer << endl;

    return 0;
}


Honers:

#include <iostream>
using namespace std;

int main()
{
    int n;
    double a[100], x, result;

    // Step 1: Degree input
    cout << "Enter degree of polynomial: ";
    cin >> n;

    // Step 2: Coefficients input
    cout << "Enter coefficients from highest degree to constant term:\n";

    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Value of x
    cout << "Enter value of x: ";
    cin >> x;

    // Step 4: Start with first coefficient
    result = a[0];

    // Step 5: Apply Horner's Rule
    for (int i = 1; i <= n; i++)
    {
        result = result * x + a[i];
    }

    // Step 6: Print result
    cout << "f(" << x << ") = " << result << endl;

    return 0;
}


Bisection:

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

Newton_raphson:

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


Newtoon_Forward :

#include <iostream>
using namespace std;

int main()
{
    int n;
    double x[20], y[20], d[20][20];
    double value, h, u, term, result;

    cout << "Enter number of points: ";
    cin >> n;

    cout << "Enter x and y values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // Step 1: Calculate h
    h = x[1] - x[0];

    // Step 2: First column of difference table
    for (int i = 0; i < n; i++)
    {
        d[i][0] = y[i];
    }

    // Step 3: Forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            d[i][j] = d[i + 1][j - 1] - d[i][j - 1];
        }
    }

    // Step 4: Value where interpolation is needed
    cout << "Enter value of x: ";
    cin >> value;

    // Step 5: Calculate u
    u = (value - x[0]) / h;

    // Step 6: Newton Forward Formula
    result = y[0];
    term = 1;

    for (int i = 1; i < n; i++)
    {
        term = term * (u - (i - 1)) / i;
        result = result + term * d[0][i];
    }

    cout << "Interpolated value = " << result << endl;

    return 0;
}

//Enter number of points: 4//
//Enter x and y values://
//1 2//
///2 8//
//3 27//
//4 64//
//Enter value of x: 2.5//
//Interpolated value = 15.5625//


bujhe nao : same

#include <iostream>
using namespace std;

int main()
{
    int n;

    // x = x-values রাখবে
    // y = y-values রাখবে
    // d = forward difference table রাখবে
    double x[20], y[20], d[20][20];

    // value = যে x value-এ interpolation করব
    // h = x-values এর common difference
    // u = Newton Forward formula-এর parameter
    // term = formula-এর coefficient term
    // result = final interpolated value
    double value, h, u, term, result;


    // Step 1: কয়টা data point আছে সেটা input নেওয়া
    cout << "Enter number of points: ";
    cin >> n;


    // Step 2: x এবং y values input নেওয়া
    cout << "Enter x and y values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }


    // Step 3:
    // x-values এর common difference h বের করা
    // Newton Forward-এ x-values equally spaced হতে হয়
    h = x[1] - x[0];


    // Step 4:
    // Difference table-এর first column-এ y-values রাখা
    for (int i = 0; i < n; i++)
    {
        d[i][0] = y[i];
    }


    // Step 5:
    // Forward difference table তৈরি করা
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            // পরের value - আগের value
            d[i][j] = d[i + 1][j - 1] - d[i][j - 1];
        }
    }


    // Step 6:
    // যে x value-এ y বের করতে চাই সেটা input নেওয়া
    cout << "Enter value of x: ";
    cin >> value;


    // Step 7:
    // u = (x - x0) / h
    u = (value - x[0]) / h;


    // Step 8:
    // Newton Forward formula-এর first term y0
    result = y[0];

    // coefficient calculation শুরু করার জন্য term = 1
    term = 1;


    // Step 9:
    // Newton Forward formula-এর remaining terms যোগ করা
    for (int i = 1; i < n; i++)
    {
        // u, u(u-1)/2!, u(u-1)(u-2)/3! ...
        // এই coefficientগুলো তৈরি করে
        term = term * (u - (i - 1)) / i;

        // Difference table-এর top row use করে result update করা
        result = result + term * d[0][i];
    }


    // Step 10:
    // Final interpolated value print করা
    cout << "Interpolated value = " << result << endl;

    return 0;
}


newton_divided :

#include <iostream>
using namespace std;

int main()
{
    int n;
    double x[20], y[20], d[20][20];
    double value, term, result;

    // Step 1: Number of points
    cout << "Enter number of points: ";
    cin >> n;

    // Step 2: Input x and y values
    cout << "Enter x and y values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // Step 3: First column = y values
    for (int i = 0; i < n; i++)
    {
        d[i][0] = y[i];
    }

    // Step 4: Divided Difference Table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            d[i][j] =
            (d[i + 1][j - 1] - d[i][j - 1])
            / (x[i + j] - x[i]); //f[X0,X1] = y1-y0/x1-x0
        }
    }

    // Step 5: Interpolation point
    cout << "Enter value of x: ";
    cin >> value;

    // Step 6: Start formula
    result = d[0][0];// 1,7,6,1 first row gula ashbe
    term = 1;

    // Step 7: Newton Divided Difference Formula
    for (int i = 1; i < n; i++)
    {
        term = term * (value - x[i - 1]);

        result = result + term * d[0][i];
    }

    // Step 8: Output
    cout << "Interpolated value = " << result << endl;

    return 0;
}




//Enter number of points: 4//
//Enter x and y values://
//1 1//
//2 8//
//3 27//
//4 64//
//Enter value of x: 2.5//
//Interpolated value = 15.625//
