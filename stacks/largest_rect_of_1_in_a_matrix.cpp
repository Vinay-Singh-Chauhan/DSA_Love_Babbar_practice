// * Approach
// step 1 : Make row for histogram algo : for every row , for every element if it is non zero add length of ones above it in the column. If the element is zero then keep it zero 
// step 2 : Apply max_reactangle_in_a_histogram algo: one by one starting from topmost row

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
vi next_pointers(vi arr){
    int n=arr.size();
    stack<int> st;
    st.push(-1);
    vi next(n);
    for(int i=n-1;i>=0;i--){
        if(st.top()!=-1 and arr[i]>arr[st.top()]){
            ;
        }
        else{
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
        }
        next[i]=st.top();
        st.push(i);
    }
    return next;
}
vi prev_pointers(vi arr){
    int n=arr.size();
    stack<int> st;
    st.push(-1);
    vi prev(n);
    for(int i=0;i<n;i++){
        if(st.top()!=-1 and arr[i]>arr[st.top()]){
            ;
        }
        else{
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
        }
        prev[i]=st.top();
        st.push(i);
    }
    return prev;
}
int max_reactangle_in_a_histogram(vi arr){
    vi next=next_pointers(arr);
    vi prev=prev_pointers(arr);
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(next[i]==-1){
            next[i]=n;
        }
        ans=max(ans,(next[i]-prev[i]-1)*arr[i]);
    }
    return ans;

}
vvi prepare_matrix(vvi arr,int n,int m){
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                continue;
            }
            arr[i][j]+=arr[i-1][j];
        }
    }
    return arr;
}
int max_area(vvi arr,int n,int m){
    int ans=INT_MIN;
    for(vi& i:arr){
        int curr_area=max_reactangle_in_a_histogram(i);
        ans=max(ans,curr_area);
    }
    return ans;
}
int32_t main()
{
    vvi arr={
    {0,1,1,0},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,0,0}};
    int n=arr.size();
    int m=arr[0].size();
    vvi prepared_matrix=prepare_matrix(arr,n,m);
    int ans=max_area(prepared_matrix,n,m);
    cout<<ans<<endl; 
    return 0;
}
