#include<bits/stdc++.h>
using namespace std;
bool required_time(int chefs[],int sz,int p,int t){
    long long  curr=0;
    for(int i=0;i<sz;i++){
        int temp=t;
        int r=1;
        while(temp>0){
            if(temp<r*chefs[i]){
                break;
            }
            temp-=r*chefs[i];
            curr++;
            r++;
        }

    }
    return curr>=p;
}
long long min_time(int chefs[], int sz, int p) 
    {
        long long l=0,r=INT_MAX;
        long long ans=-1;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(required_time(chefs,sz,p,m)){
                r=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<min_time(arr,n,m)<<endl;;
    }
    
    
}