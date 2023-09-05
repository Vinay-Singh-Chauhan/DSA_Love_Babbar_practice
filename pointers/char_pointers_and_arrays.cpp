#include<iostream>
using namespace std;
int main()
{
    char arr[10]="abcdefgh";// gives risk of writeing over some memory thus decaring array is good
    cout<<arr<<endl; //prints entire array

    char ch='a';
    char *c=&ch;
    cout<<c<<endl;//prints till '\0' id found

    char *t=&arr[0];
    cout<<t<<endl;//prints entire array

    // char *tt=arr[2];  //gives array
    // cout<<tt<<endl;

    return 0;
}