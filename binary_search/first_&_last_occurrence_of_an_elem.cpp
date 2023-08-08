#include<bits/stdc++.h>
using namespace std;
int binary_search_l(int l,int r,int t,vector<int>& a){
    int m=r+(l-r)/2;
    if(l>r){
        return INT_MAX;
    }
    if(a[m]==t){
        return min(binary_search_l(l,m-1,t,a),m);
    }else if(a[m]>t){
        return binary_search_l(l,m-1,t,a);
        // l=m+1;
    }else{
        return binary_search_l(m+1,r,t,a);
        // r=m-1;
    }
    return INT_MAX;
}
int binary_search_r(int l,int r,int t,vector<int>& a){
    int m=r+(l-r)/2;
    if(l>r){
        return INT_MIN;
    }
    if(a[m]==t){
        return max(binary_search_r(m+1,r,t,a),m);
    }else if(a[m]>t){
        return binary_search_r(l,m-1,t,a);
        // l=m+1;
    }else{
        return binary_search_r(m+1,r,t,a);
        // r=m-1;
    }
    return INT_MIN;

}
int main()
{
    int test_case;
    cin>>test_case;
    for(int test_c=0;test_c<test_case;test_c++){
        int n,t;
    
        cin>>n>>t;
        vector<int>a;
        for(int i=0;i<n;i++){
            int ai;
            cin>>ai;
            a.push_back(ai);
        }
        int l=0,r=n-1;
        cout<<binary_search_l(0,n,t,a)<<endl;
        cout<<binary_search_r(0,n,t,a)<<endl;
        }
    return 0;
}