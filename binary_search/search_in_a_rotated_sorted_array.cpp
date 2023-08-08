#include<bits/stdc++.h>
using namespace std;

//** approach 1: Basic
// ===========================================================================
int get_pivot(vector<int>& arr,int n){
    int ans=-1;
    int l=0,r=n-1;
    while(l<r){
        int m=l+(r-l)/2;
        if(arr[m]>=arr[0]){
            l=m+1;
        }else{
            ans=m;
            r=m;
        }
    }
    return ans;
}

int binary_search(vector<int>& arr,int l,int r,int k){
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==k){
            return m;
        }else if(arr[m]>arr[l]){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return -1;
}
// =========================================================================
//! TODO:
//! approach 2
//! approach 3
//** all three approch have same complexities of log(N)

int main()
{
    int ans=-1;
    vector<int>arr={8,10,17,1,3};
    int n=arr.size();
    int pivot=get_pivot(arr,n);
    int k=10;
    if(k<=arr[n-1]){
        cout<<binary_search(arr,pivot,n-1,k);
    }else{
        cout<<binary_search(arr,0,pivot,k);

    }
    return 0;
}