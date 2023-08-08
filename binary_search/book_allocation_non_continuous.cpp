#include<bits/stdc++.h>
using namespace std;
// n is the number of students
int solve(int n,vector<int> v){
    priority_queue<int,vector<int>,greater<int> > pq;
    if(n<=v.size()){
        return *max_element(v.begin(),v.end());
    }
    for(int i=0;i<n;i++){ 
        pq.push(v[i]);
    }
    for(int i=n;i<v.size();i++){
        int top = pq.top();
        pq.pop();
        top += v[i];
        pq.push(top);
    }
    int maxi = INT_MIN;
    while(!pq.empty()){
        maxi = max(maxi,pq.top());
        pq.pop();
    }
    return maxi;
}
int main()
{
    vector<int>books={12,34,67,90};
    sort(books.rbegin(),books.rend());
    cout<<solve(2,books)<<endl;
    // int n=5;
    // int students=3;
    // int l=0,r=books[n-1];
    // int ans=-1;
    // while(l<=r){
    //     int m=l+(r-l)/2;
    //     int st=required_students(m,books,n);
    //     if(st==n){
    //         ans=max(ans,m);
    //         r=m-1;
            
    //     }else if(st<n){
    //         l=m+1;
    //     }else{
    //         r=m-1;
    //     }
    // }

    return 0;
}