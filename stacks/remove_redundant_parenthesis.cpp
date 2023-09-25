#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
bool check_redundant_parenthesis(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]==')' and st.top()=='('){
            return true;
        }
        else if(s[i]==')' and st.top()!='('){
            while(!st.empty() and st.top()=='(') st.pop();
            st.pop();
        }
        else if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='/'||
s[i]=='*')   {
        st.push(s[i]);
}        
        }
        return false;
}

int32_t main()
{
    string input="(+)";
    cout<<check_redundant_parenthesis(input)<<endl;
    return 0;
}