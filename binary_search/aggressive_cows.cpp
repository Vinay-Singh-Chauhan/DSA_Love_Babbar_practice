#include<bits/stdc++.h>
using namespace std;
bool required_stalls(int stalls[],int sz,int cows,int dist){
    // int st=1;
    cows--;
    int curr=stalls[0];
    for(int i=1;i<sz;i++){
        if(stalls[i]-curr>=dist){
            cows--;
            curr=stalls[i];
        }
    //    if(curr+stalls[i]>dist){
    //         st++;
    //         curr=stalls[i];
    //    }
    //    curr=stalls[i];

    }
    return cows<=0;
}
// N is size of array
// M is number of painters
long long max_dist(int stalls[], int sz, int cows) 
    {
        long long l=0,r=INT_MAX;
        long long ans=-1;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(required_stalls(stalls,sz,cows,m)){
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
    int arr[5]={1,2,8,4,9};
    sort(arr,arr+5);
    // int n=2;
    int aggressive_cows=3;
    cout<<max_dist(arr,5,aggressive_cows);
    return 0;
}