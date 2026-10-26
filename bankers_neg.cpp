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
