#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=-1;
    vector<int>arr={1,7,3,6,5,6};

    // creating a prefix array
    vector<int>pre;
    pre.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        pre.push_back(pre[i-1]+arr[i]);
    }
    pre.insert(pre.begin(),0);
    int end=pre.size()-1;
    for(int i=1;i<pre.size();i++){
        if(pre[i-1]==pre[end]-pre[i]){
            ans=i-1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}