#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& a, int x)
{
    int n=a.size();
    int l=0,r=n-1;
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (a[m] == x)
        return m;

      if (a[m] < x)
        l = m + 1;

      else
        r = m - 1;
    }

    return -1;
}

int main()
{
	int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<binarySearch(a,10)<<endl;
	return 0;
}
