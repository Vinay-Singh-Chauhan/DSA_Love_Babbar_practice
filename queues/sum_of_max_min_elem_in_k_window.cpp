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

vector<string> split(string s, string delimiter) {
size_t pos_start = 0, pos_end, delim_len = delimiter.length();
string token;
vector<string> res;
while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr (pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back (token);
}
res.push_back (s.substr (pos_start));
return res;
}

int solve(vector<int>& arr, int k,int n){
    deque<int>maxi;
    deque<int>mini;
    for(int i=0;i<k;i++){
        while(!maxi.empty() and arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() and arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    for(int i=k;i<n;i++){
        ans+=arr[maxi.front()];
        ans+=arr[mini.front()];
        while(!maxi.empty() and i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() and i-mini.front()>=k){
            mini.pop_front();
        }
        while(!maxi.empty() and arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() and arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
    }
     ans+=arr[maxi.front()];
    ans+=arr[mini.front()];
    return ans;
}
int32_t main()
{
    int n,k;
    cin>>n;
    
    vector<int>arr(n);
    for(auto &i:arr) cin>>i;
    cin>>k;
    cout<<solve(arr,k,n);
    return 0;
}