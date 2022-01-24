#include<bits/stdc++.h>
using namespace std;
int solve(int x,int y,int p){
    int answer=1;
    x=x%p;
    
    for(int i=0;i<y;i++){
        answer=answer*x;
        answer=answer%p;
    }
    return answer;
}
int main()
{
    int x,y,p;
    cin>>x>>y>>p;
    cout<<solve(x,y,p)<<endl;
    return 0;
}
