#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& a,int l,int r, int x)
{
	if (l <= r) {
		int m = l + (r - l) / 2;

		if (a[m] == x)
			return m;

		if (a[m] < x)
			return binarySearch(a,m+1,r,x);

		else
			return binarySearch(a,l,m-1,x);
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
    cout<<binarySearch(a,0,n-1,11)<<endl;
	return 0;
}
