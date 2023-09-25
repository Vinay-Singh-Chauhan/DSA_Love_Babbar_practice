//* Question: Implement n stacks in an array

// * Approach
// there will be an array arr for storing elements;
// there will be an array tops storing top index for all stacks
// there will be an array prevs which will store:
    // i. next empty space in array other than the index itself if there is no  element stored in the index of arr
    // ii. index of second to top element index.



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
class n_stacks{
    public:
    int free_space;
    vi arr;
    vi tops;;
    vector<int> prevs;
    n_stacks(int n,int k){
        free_space=0;
        tops.resize(k,-1);
        prevs.resize(n);
        fl(int,i,0,n-1){
            arr[i]=i+1;
        }
        arr[n-1]=-1;

    }
    int push(int elem,int st){
        if(free_space==-1) return -1;
        int index=free_space;
        free_space=prevs[index];
        prevs[index]=tops[st];
        arr[index]=elem;
        top[st]=index;
        return index;
    }
    int pop(int st){
        if(top[st]==-1) return -1 ;
        int index=top[st];
        top[st]=prevs[index];
        prevs[index]=free_space;
        free_space=index;
        return arr[index]; 
    }
};
int32_t main()
{
    
    return 0;
}