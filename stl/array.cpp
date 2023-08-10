// * stl array is implemented by simple static array hence is not widely used

#include<array>
#include<bits/stdc++.h>
int main()
{
    array<int,5>={1,2,3,4,5};
    a[3]=6;
    cout<<a.at(3)<<endl;
    cout<<"size of array "<<a.size()<<endl;
    cout<<"is array empty?"<<a.empty()<<endl;
    cout<<"first element"<<a.front()<<endl;
    cout<<"last element"<<a.back()<<endl;
    return 0;
}