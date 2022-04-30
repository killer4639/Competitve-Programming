#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<ll, ll>>> g;
void dijkstra(ll x, vector<ll> &distance, vector<bool> &processed)
{
    ll n = distance.size();
    for (ll i = 0; i < n; i++)
        distance[i] = INT_MAX;
    distance[x] = 0;

    priority_queue<pair<ll, ll>> q;
    q.push({0, x});
    while (!q.empty())
    {

        ll a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : g[a])
        {
            ll b = u.first, w = u.second;
            if (distance[a] + w < distance[b])
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    return;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> distance(n);
    vector<bool> processed(n, false);
    dijkstra(0, distance, processed);

    for (ll i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    return 0;
}
