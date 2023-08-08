#include<bits/stdc++.h>
using namespace std;
bool required_painters(int board,int boards[],int painters,int sz){
    int st=1;
    int curr=0;
    int no=sz;
    for(int i=0;i<no;i++){
        if(boards[i]>board){
            return false;
        }
       if(curr+boards[i]>board){
            st++;
            curr=0;
       }
       curr+=boards[i];

    }
    return st<=painters;
}
// N is size of array
// M is number of painters
long long findBoards(int boards[], int N, int M) 
    {
        long long l=0,r=INT_MAX;
        long long ans=-1;
        if(M==N){
            return *max_element(boards,boards+N);
        }
        
        while(l<=r){
            long long m=l+(r-l)/2;
            if(required_painters(m,boards,M,N)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
int main()
{
    int arr[4]={5,5,5,5};
    // int n=2;
    int painters=2;
    cout<<findBoards(arr,4,painters);
    return 0;
}