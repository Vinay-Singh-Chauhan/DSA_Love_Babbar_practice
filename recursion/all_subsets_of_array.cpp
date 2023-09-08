#include<bits/stdc++.h>
using namespace std;
void subset(vector<int>& arr,vector<int>& cur_subset,int start,int size,vector<vector<int>>& ans){
    if(start>=size){
        ans.push_back(cur_subset);
        return;
    }
    subset(arr,cur_subset,start+1,size,ans);
    cur_subset.push_back(arr[start]);
    subset(arr,cur_subset,start+1,size,ans);
    cur_subset.pop_back();
    return;
}
int main()
{
    vector<int> arr;
    arr={1,2,3};
    vector<vector<int>> ans;
    vector<int> temp_output;
    subset(arr,temp_output,0,3,ans);
    for(auto v:ans){
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}