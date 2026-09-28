#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    if (n == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    long long a = 0, b = 1, c = 1, d = 2;
    long long sum;

    for (int i = 4; i <= n; i++)
    {
        sum = a + b + c + d;

        a = b;
        b = c;
        c = d;
        d = sum;
    }

    cout << sum << endl;

    return 0;
}