#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int parent[100005];
bool cycle;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[par])
        {
            if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (cycle)
        cout << "Cycle is present in the graph" << endl;
    else
        cout << "Cycle is not present in the graph" << endl;
    return 0;
}