#include<iostream>
using namespace std;
int main()
{
    int i=5;
    int *p=&i;
    int **pp=&p;
    int ***ppp=&pp;
    cout<<"Value of i "<<i<<endl;
    cout<<"Address of i "<<&i<<endl;
    cout<<"Value of p "<<p<<endl;
    cout<<"Value at p "<<*p<<endl;
    // cout<<"Value of pp "<<<<endl;
    // cout<<"Value of p"<<endl;

    return 0;
}