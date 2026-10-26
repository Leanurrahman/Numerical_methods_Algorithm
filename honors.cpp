#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a[100];

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    double x;
    cin >> x;

    double result = a[0];

    for (int i = 1; i <= n; i++) {
        result = result * x + a[i];
    }

    cout << result << endl;

    return 0;
}
