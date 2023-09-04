#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
int32_t main()
{
    // for this matrix should be such that it is sorted in linear fashiom=n
    vvi m(4,vi(4));
    m={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int row=m.size(),col=m[0].size();
    int target=1;
    int start=0;
    int end=row*col -1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(m[mid/col][mid%col]==target){
            cout<<"Found @ index: "<<mid/col<<","<<mid%col<<endl;
            break;
        }
        if(m[mid/col][mid%col]<target){
            start=mid+1;
        }
        if(m[mid/col][mid%col]>target){
            end=mid-1;
        }
    }
    return 0;
}