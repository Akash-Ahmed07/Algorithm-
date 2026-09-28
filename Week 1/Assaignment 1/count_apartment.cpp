#include <bits/stdc++.h>
using namespace std;

char adj_mat[1005][1005];
bool vis[1005][1005];

int n, m;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && adj_mat[ci][cj] == '.')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
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
            cin >> adj_mat[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int apartment = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj_mat[i][j] == '.' && !vis[i][j])
            {
                apartment++;
                bfs(i, j);
            }
        }
    }

    cout << apartment << endl;

    return 0;
}