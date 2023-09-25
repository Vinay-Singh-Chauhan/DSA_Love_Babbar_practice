//* Approach
// step1: check size of string if it is odd then return -1
// step2: remove valid parts
// step3: count opening braces as a and closing braces as b return ((a+1)/2 + (b+1)/2 )


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
string remove_valid_parts(string s){
    stack<char> st;
    for( char i: s){
        if(i=='}'){
            if(!st.empty() and st.top()=='{'){
                st.pop();
            }else{
                st.push(i);
            }
        }
        else
        st.push(i);
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int min_cost(string s){
    
    return s.size()/2;
}
int32_t main()
{
    string s="}}}}}{";
    if(s.size()%2!=0) cout<<-1<<endl;
    else{
        string rs=remove_valid_parts(s);
        cout<<min_cost(rs);
    }
    
    return 0;
}