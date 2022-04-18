#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> g;
vector<int> visited;
void bfs(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
       int s = q.front(); 
       q.pop();
       cout<<s+1<<" ";
       for (auto u : g[s]) {
           if (visited[u]) continue;
           visited[u] = true;
           q.push(u);
        } 
    }
    return;
}
      
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    visited.assign(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(0);
    return 0;
}
