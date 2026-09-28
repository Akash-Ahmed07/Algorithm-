#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    const long long INF = 1e18;

    for (int i = 0; i <= n; i++)
        dis[i] = INF;

    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dis[a] != INF && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;

        if (dis[a] != INF && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int destination;
        cin >> destination;

        if (dis[destination] == INF)
            cout << "Not Possible" << endl;
        else
            cout << dis[destination] << endl;
    }

    return 0;
}