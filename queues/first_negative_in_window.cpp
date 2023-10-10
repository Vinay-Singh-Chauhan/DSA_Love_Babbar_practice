// ! OPTIMAL APPROACH PENDING -- TO BE SEARCHED ONLINE

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
    vi arr(5);
    arr={-8,2,3,-6,10};
    queue<int> q;
    vi ans;
    int k=2;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    if(q.size()>0){
        ans.push_back(q.front());
    }else{
        ans.push_back(-1);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]<0){
            q.push(i);
        }
        if(q.size()>0 and i-q.front()>=k){
            q.pop();
        }
        if(q.size()>0){
            ans.push_back(q.front());
        }else{
            ans.push_back(-1);
        }
    }
    for(auto i:ans) cout<<(i>=0?arr[i]:0)<<" ";
    cout<<endl;
    return 0;
}