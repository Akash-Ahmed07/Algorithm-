#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int vis[1005][1005];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;

    int area = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int par_i = p.first;
        int par_j = p.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                area++;
            }
        }
    }

    return area;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int area = bfs(i, j);
                mn = min(mn, area);
            }
        }
    }

    if (mn == INT_MAX)
        cout << -1 << endl;
    else
        cout << mn << endl;

    return 0;
}