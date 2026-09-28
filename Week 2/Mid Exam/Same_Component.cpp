#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int vis[1005][1005];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, di, dj;

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
            }
        }
    }
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

    int si, sj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));

    if (grid[si][sj] == '-' || grid[di][dj] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    bfs(si, sj);

    if (vis[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}