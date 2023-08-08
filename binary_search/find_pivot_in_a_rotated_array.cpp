#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=-1;
    vector<int>arr={8,10,17};
    int n=arr.size();
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
    cout<<ans<<endl;
    return 0;
}