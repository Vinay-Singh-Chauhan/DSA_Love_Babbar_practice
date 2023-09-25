#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
class spstack{
    public:
    int mini;
    stack<int>st;
    spstack(){
        mini=INT_MAX;
    }
    int push(int n){
        if(st.empty()){
            mini=min(mini,n);
            st.push(n);
            return n;
        }
        if(n<mini){
            st.push(2*n-mini);
            mini=n;
            return n;
        }
        st.push(n);
        return n;
    }
    int pop(){
        if(st.empty()) return -1;
        if(st.top()<=mini){
            int prevMin=mini;
            mini=2*mini-st.top();
            st.pop();
            return prevMin;
        }
        int a=st.top();
        st.pop();
        return a;
    }
    int getMin(){
        if(st.empty()){
            return -1;
        }
        return mini;
    }
    int top(){
        if(st.empty()) return -1;
        if(st.top()<=mini){
            return mini;
        }
        int a=st.top();
        return a;
    }
    bool isEmpty(){
        return st.empty();
    }
};
int32_t main()
{
    
    return 0;
}