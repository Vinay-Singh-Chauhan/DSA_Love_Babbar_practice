#include<bits/stdc++.h>
using namespace std;
#define int long long
int binary_search(vector<int>arr,int s,int e,int t){
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]==t){
            return m;
        }else if(arr[m]<t){
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return -1;
}
int32_t main()
{
    
        int n,d;
        cin>>n>>d;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int c=0;
        for(int i=0;i<n-2;i++){
            int idx=binary_search(a,i+1,n,a[i]+d);
            if(idx!=-1){
                int sidx=binary_search(a,idx+1,n,a[idx]+d);
            // cout<<sidx<<endl;
                if(i<idx and idx<sidx and sidx!=-1){
                    c++;
                }
            }
        }
        cout<<c<<endl;
        
    return 0;
}