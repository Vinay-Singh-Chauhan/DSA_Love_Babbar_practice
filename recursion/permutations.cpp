#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
void permutation(string s,vector<string>& ans,int index){
    if(index>=s.size()) {
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++){
        swap(s[i],s[index]);
        permutation(s,ans,index+1);
        swap(s[i],s[index]);//backtracking
    }
}
int32_t main()
{
    vector<string>ans;
    string s="abc";
    permutation(s,ans,0);
    for(string i:ans) cout<<i<<endl;
    return 0;
}