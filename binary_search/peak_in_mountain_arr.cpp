#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={1,2,3,4,5,4,4,3,2,1};
   int l=0,r=arr.size()-1;
    int ans=-1;
    while(l<=r){
        // ans=l;
        int m=l+(r-l)/2;
        cout<<m<<endl;
        if(m==arr.size()-1){
            break;
        }
        else if(arr[m+1]>arr[m]){
            l=m+1;
        }
        else{
            ans=m;
            r=m-1;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}