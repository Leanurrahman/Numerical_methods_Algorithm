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
            / (x[i + j] - x[i]);
        }
    }

    // Step 5: Interpolation point
    cout << "Enter value of x: ";
    cin >> value;

    // Step 6: Start formula
    result = d[0][0];
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
