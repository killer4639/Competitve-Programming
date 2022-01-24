#include<bits/stdc++.h>
using namespace std;
int solve(int x,int y,int p){
    
    int answer=1;
    
    x=x%p;
    
    while(y>0){
        if(y&1)
        {
            answer=answer*x;
            answer=answer%p;
        }
        
        x=x*x;
        
        x=x%p;
        
        y=y/2;
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
