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
    queue<int> q;
    vi elems={1,2,3,4,5};
    for(auto i:elems) q.push(i);
    int k=3;
    int n=5;
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    while(q.size()>0){
        cout<<q.front()<<" "; 
        q.pop();
    }
    cout<<endl;
    return 0;
}