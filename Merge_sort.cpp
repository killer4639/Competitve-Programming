#include <bits/stdc++.h>
using namespace std;

void merge_arrays(vector<int> &a,int l, int mid, int r){
    vector<int> new_arr;
    int i=l, j=mid+1;

    while(1){
        if((i==mid+1) and (j==r+1)){
            break;
        }
        if(i==mid+1){
            new_arr.push_back(a[j]);
            j++;
        }
        else if(j==r+1){
            new_arr.push_back(a[i]);
            i++;
        }
        else{
            if(a[i]<a[j]){
                new_arr.push_back(a[i]);
                i++;
            }
            else{
                new_arr.push_back(a[j]);
                j++;
            }
        }
    }
    for(int idx=0;idx<new_arr.size();idx++){
        a[l+idx]=new_arr[idx];
    }
    return;
}

void merge_sort_array(vector<int>& a, int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        // 1
        merge_sort_array(a, l, mid);
        merge_sort_array(a, mid+1, r);

        // 2
        merge_arrays(a, l, mid, r);
    }
    return;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    merge_sort_array(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
