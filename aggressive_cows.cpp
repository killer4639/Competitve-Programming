#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &x, int mid, int c)
{
    int cows=1;               
    int lastPos=x[0];
    for(int i=1;i<x.size();i++)
    {
        if(x[i]-lastPos>=mid)
        {
            cows++;
            lastPos=x[i];
            if(cows>=c){ 
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &x, int c)
{
    int n=x.size();
    sort(x.begin(),x.end());
    int low=1,high=x[n-1]-x[0];
    int d;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(x,mid,c))
        {
            d=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return d;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> x(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        cout<<aggressiveCows(x,c)<<endl;
    }
    
    return 0;
}
