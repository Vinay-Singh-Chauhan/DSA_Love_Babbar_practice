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
    string s="aabbc";
    queue<char> q;
    vi count(26,0);
    int i=0;
    string ans="";
    while(i<s.size()){
        if(count[s[i]]==0){
            q.push(s[i]);
        }
        count[s[i]]++;
        while(q.size()>0 and count[q.front()]>1){
            q.pop();
        }
        if(q.size()!=0){
            ans.push_back(q.front());
        }else{
            ans.push_back('#');
        }
        i++;
    }
    cout<<ans<<endl;
    return 0;
}