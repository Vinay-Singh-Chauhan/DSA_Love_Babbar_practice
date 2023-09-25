//* Approach
// for every ith element of array get its next smaller elements index  and its previous elements index and store them in an array
// then area for ith bar is : (next[i]-prev[i] -1)*arr[i].
// ! handle case where next[i]==-1


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
vector<int> nextSmallerElements(vector<int>& arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        if(st.top()!=-1 and arr[st.top()]<arr[i]){
            ;
        }else{
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElements(vector<int>& arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++){
        if(st.top()!=-1 and arr[st.top()]<arr[i]){
            ;
        }else{
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
int32_t main()
{
    int ans=INT_MIN;
    vector<int> arr={2,2,2,2};
    int n=arr.size();
    vi nexts = nextSmallerElements(arr);
    vi prevs = prevSmallerElements(arr);
    for(int i=0;i<n;i++){
        if(nexts[i]==-1) nexts[i]=n;
        ans=max((nexts[i]-prevs[i]-1)*arr[i],ans);
    }
    
    cout<<ans<<endl;
    return 0;
}