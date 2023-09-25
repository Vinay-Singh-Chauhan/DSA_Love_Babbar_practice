#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
void sorted_insert(stack<int>& s,int e){
    // cout<<"call at "<<e<<endl;
    if(s.empty()) {
        s.push(e);
        return;
    }
    stack<int> st;
    while(!s.empty() and s.top()>e){
        st.push(s.top());
        s.pop();
    }
    s.push(e);
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }
}
void sort_stack(stack<int>& s){
    if(s.empty()) return;
    int a=s.top();
    s.pop();
    sort_stack(s);
    sorted_insert(s,a);
    // s.push(a);
}


int32_t main()
{
    stack<int>st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    sort_stack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}