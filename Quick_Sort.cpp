#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r)
{
  int random=l + rand() % (r - l);
	swap(a[l], a[random]);
	
	int pivot = a[l];

	int count = 0;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= pivot)
			count++;
	}

	int pivotIndex = l + count;
	swap(a[pivotIndex], a[l]);

	int i = l, j = r;

	while (i < pivotIndex && j > pivotIndex) {

		while (a[i] <= pivot) {
			i++;
		}

		while (a[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(a[i], a[j]);
            i++, j--;
		}
	}

	return pivotIndex;
}

void quick_sort_array(vector<int> &a,int l, int r)
{

	if (l<r){

	    int p = partition(a, l, r);

	    quick_sort_array(a, l, p - 1);

	    quick_sort_array(a, p + 1, r);
    }
	
    return;
}

int main()
{

	int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort_array(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

	return 0;
}
