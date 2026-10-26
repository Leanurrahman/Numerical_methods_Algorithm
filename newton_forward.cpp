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
