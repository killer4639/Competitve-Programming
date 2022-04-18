#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> g;
vector<int> visited;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    cout<<s+1<<" ";
    for (auto u: g[s]) {
        dfs(u); 
    }
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
    dfs(0);
    return 0;
}
