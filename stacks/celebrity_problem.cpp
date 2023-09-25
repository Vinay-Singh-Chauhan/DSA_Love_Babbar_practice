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
    stack<int> st;
    vvi arr={{0,1},{1,0}};
    int n=2;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()!=1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(arr[a][b]==1){
            st.push(b);
        }else{
            st.push(a);
        }
    }
    // st.top() is a potential celebrity
    bool check=true;
    for(int i=0;i<n;i++)
        if(arr[st.top()][i]==1){
            check=false;
    }
    for(int i=0;i<n;i++)
        if(i!=st.top() and arr[i][st.top()]==0){
            check=false;
    }
    if(check)
    cout<<st.top()<<endl;
    else 
    cout<<-1<<endl;
    return 0;
}