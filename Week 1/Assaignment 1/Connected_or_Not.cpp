#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (u == v || adj_mat[u][v])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}