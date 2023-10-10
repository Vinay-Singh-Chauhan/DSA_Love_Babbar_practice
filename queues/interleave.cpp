#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
int gcd( int a,  int b)
{
    if (b == 0)
    return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int32_t main()
{
    vi arr={11,12,13,14,15,16,17,18};
    stack<int> st;
    queue<int> q;

    for(auto i:arr){
        q.push(i);
    }

    // solution start
    int sz=q.size();
    fl(int,i,0,sz/2){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    fl(int,i,0,sz/2){
        q.push(q.front());
        q.pop();
    }   

    fl(int,i,0,sz/2){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}