#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[50005];
bool visit[50005];
int level[50005];
int parent[50005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << " ";

        for (int child : adj_list[par])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
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
    int dst, src;
    cin >> src >> dst;
    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(src);
    cout << level[dst] << endl;
    vector<int> path;
    int node = dst;
    while (node != -1)
    {
       path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
    return 0;
}