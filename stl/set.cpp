// unique elements are stored
// implemented using bst
// u can insert and delete elements but can not modify them
// elements are sorted
// it is slow than unordered set

#include<iostream>
#include<set>
using namespace std;
int main(){
    
    set<int>s;

    s.insert(1);
    s.insert(2);

    s.size();
    s.empty();

    s.erase(s.begin());

    cout<<s.count(5)<<endl;//return whether it is present or not

    set<int>:: iterator it=s.begin();

    set<int>::iterator itr;

    itr=s.find(5);

    cout<<<*itr<<endl; 
// insert, erase, count ,find===O(logN)
// size,empty,begin,-== O(1)

}