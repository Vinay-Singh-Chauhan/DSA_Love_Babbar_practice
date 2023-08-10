// * vector is a dynamic array
// when element is pushed in a vector filled completely then it creates another vector of double size copies it and dump previous vector
// you can use shrink to fit function also to shrink its size


#include<vector>
#include<bits/stdc++.h>
int main()
{
    vector<int> v;
    // capacity refers to limit of elements that can be stored 
    cout<<"Capacity of newly declared vector is "<<v.capacity()<<endl;
    // size refers to the current number of elemnets in vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    v.pop_back();

    cout<<v.at(2);
    cout<<v.front();
    cout<<v.back();


    v.clear();
    // above call will make vector's size =0 but not capacity
    v.begin();
    v.end();

    vector<int> a(4,1);

    vector<int>last(a);

    cout<<last.empty();
    return 0;
}