#include<bits/stdc++.h>
using namespace std;
int solve(int x,int y,int p){
    
    if(y==0){
        return 1;
    }
    
    x=x%p;
    
    int answer=solve(x,y/2,p);
    answer=answer*answer;
    answer=answer%p;
    
    if(y%2==1){
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
