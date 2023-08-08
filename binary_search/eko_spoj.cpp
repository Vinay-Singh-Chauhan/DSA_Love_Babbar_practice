#include<bits/stdc++.h>
using namespace std;
bool required_height(int trees[],int sz,int meters,int height){
    long long  curr=0;
    for(int i=0;i<sz;i++){
        curr+=max(0,trees[i]-height);

    }
    return curr>=meters;
}
long long max_height(int trees[], int sz, int meters) 
    {
        long long l=0,r=INT_MAX;
        long long ans=-1;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(required_height(trees,sz,meters,m)){
                l=m+1;
                ans=m;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
int main()
{
    
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<max_height(arr,n,m)<<endl;;
    
}