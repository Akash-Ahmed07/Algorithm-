#include <bits/stdc++.h>
using namespace std;
int par[1000005];
int group_size[100005];
int cmp, mx;



int find(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = find(par[node]);
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(leader1 == leader2) return;
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        group_size[i] = 1;
    }

    cmp = n;
    mx = 1;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }

    return 0;
}