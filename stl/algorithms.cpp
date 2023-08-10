#include<iostream>
#include<bits/stdc++>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v={1,2,3,4,5,6,7,8,9};
    // binary search
    cout<<binary_search(v,begin(),v.end(),5);//returns true or false

    // lower bound
    cout<<lower_bound(v.begin(),v.end(),6);//returns iterator

    // upper bound
    cout<<upper_bound(v.begin(),v.end(),6);//returns iterator

    int a=2,b=3;
    // max
    cout<<max(a,b);

    // min
    cout<<min(a,b);

    // swapping values
    cout<<swap(a,b);


    string s="vinay";
    // reverse
    reverse(s.begin(),s.end());

    // rotating a vector at v.begin()+1
    rotate(v.begin(),v.begin()+1,v.end());

    // sorting
    sort(v.begin(),v.end());/
    // this sorting is done using intro sort
    // intro sort is a combination of insertion sort, quick sort, and heapsort

    

    return 0;
}