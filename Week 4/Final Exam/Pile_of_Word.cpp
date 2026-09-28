#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        if (a.length() != b.length())
        {
            cout << "NO" << endl;
            continue;
        }

        int cnt[26] = {0};

        for (int i = 0; i < a.length(); i++)
        {
            cnt[a[i] - 'a']++;
            cnt[b[i] - 'a']--;
        }

        bool flag = true;

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}