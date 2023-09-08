#include<bits/stdc++.h>
using namespace std;
void subsequence(string& s,string& cur_str,int start,int size,vector<string>& ans){
    if(start>=size){
        ans.push_back(cur_str);
        return;
    }
    subsequence(str,cur_str,start+1,size,ans);
    cur_str.push_back(str[start]);
    subsequence(str,cur_str,start+1,size,ans);
    cur_str.pop_back();
    return;
}
int main()
{
    string str="abc";
    vector<string> ans;
    string temp_output="";
    subsequence(str,temp_output,0,3,ans);
    for(auto v:ans){
        cout<<v<<endl;
    }
    return 0;
}