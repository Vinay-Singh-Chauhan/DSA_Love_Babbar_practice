#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
void solve(stack<int> st,int org_sz){
    if(st.size()>org_sz/2) return;
    if( st.size() == org_sz/2){
        st.pop();
        return;
    }
    int e=st.top();
    st.pop();
    solve(st.)
}
int32_t main()
{
    
    return 0;
}