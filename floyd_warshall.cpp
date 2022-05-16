#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = (int)(1e18);
void run()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void floyd_warshal(vector<vector<int>> adj)
{
    int n = adj.size() - 1;
    vector<vector<int>> distance(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else if (adj[i][j])
                distance[i][j] = adj[i][j];
            else
                distance[i][j] = INT_MAX;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    run();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    floyd_warshal(adj);
    return 0;
}
