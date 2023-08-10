// * deque is doubly ended queue i.e. insertion/deletion can be performed on both the ends
// * it is also dynamic

#include<deque>
#include<bits/stdc++.h>
int main()
{
    deque<int> d;
    
    d.push_back(1);
    d.push_front(2);

    d.pop_back();
    d.pop_front();

    cout<<d.at(1);
    cout<<d.front(1);
    cout<<d.back(1);

    cout<<d.empty();

    d.erase(d.begin(),d.begin()+1);
    // erase changes size






    return 0;
}