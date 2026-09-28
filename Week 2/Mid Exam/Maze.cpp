#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> par[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;
    par[si][sj] = {-1, -1};

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

            if (valid(ci, cj) && !vis[ci][cj] &&
                (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = {par_i, par_j};
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int si, sj;
    int di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    if (!vis[di][dj])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }

        return 0;
    }

    int x = di;
    int y = dj;

    while (!(x == si && y == sj))
    {
        if (grid[x][y] != 'D')
            grid[x][y] = 'X';

        int px = par[x][y].first;
        int py = par[x][y].second;

        x = px;
        y = py;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}