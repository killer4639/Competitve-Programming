#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> g;
vector<int> color;
bool dfs(int s,int p) {
    color[s]=1;
    for (auto u: g[s]) {
        if(u!=p){
            if(color[u]==1){
                return true;
            }
            else if(color[u]==0){
                if(dfs(u,s)){
                    return true;
                }
            }
        }
    }
    color[s]=2;
    return false;
}
      
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    color.assign(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        if(color[i]==0){
            if(dfs(i,-1)){
                cout<<"Cycle detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"No cycle detected"<<endl;
    return 0;
}
