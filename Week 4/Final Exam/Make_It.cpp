#include <bits/stdc++.h>
using namespace std;

bool vis[100005];

bool make_it(int n)
{
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == n)
            return true;

        int a = x + 3;
        int b = x * 2;

        if (a <= n && !vis[a])
        {
            vis[a] = true;
            q.push(a);
        }

        if (b <= n && !vis[b])
        {
            vis[b] = true;
            q.push(b);
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(vis, false, sizeof(vis));

        if (make_it(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}