// map is a key value store with unique keys
// one key points to one or one list of value only
// slower than unordered map
// sorted
// implemented using bst or red-black tree;
// unordered map is implemented using hashtable


#include<iostream>
#include<map>
using namespace std;
int main(){
    
    map<int,string>mp;

    mp[1]="vinay";
    mp[2]="singh";
    mp[3]="chauhan";

    mp.insert(5,"bheem");

    cout<<mp.count(1);

    mp.erase(5);//only key need to be passed


// complexity is O(logN)
// in case of unordered map it is O(1)




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

auto it=mp.find(2);//returns iterator to the key-value pair


}