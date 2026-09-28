#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[50005];
bool visit[50005];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;

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
    memset(visit, false, sizeof(visit));
    int src, dest;
    cin >> src >> dest;
    bfs(src);
    if (visit[dest])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}