// * list is a doubly linked list.
// there is no random access


#include<list>
#include<bits/stdc++.h>
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);

    
    l.pop_back();
    l.pop_front();

    cout<<l.size();
    cout<<l.front();
    cout<<l.back();

    list<int>n(5,100);
    list<int>l2(n);

    return 0;
}