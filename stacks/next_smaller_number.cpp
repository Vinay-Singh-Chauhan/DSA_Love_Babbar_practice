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
    vector<int> arr={2,1,4,3};
    vector<int>ans(arr.size());
    stack<int>st;
    st.push(-1);
    int i=arr.size()-1;
    while(i>=0){
        if(st.top()<arr[i]){
            ans[i]=st.top();
        }else{
            while(st.top()>arr[i]){
                st.pop();
            }
            ans[i]=st.top();
        }
        st.push(arr[i]);
        i--;
    }
    for(int i:ans) cout<<i<<endl;
    return 0;
}