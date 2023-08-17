#include<iostream>
using namespace std;
int main()
{
    char name[20];
    cin>>name;
    // works
    // __________________________________
    // |b|a|b|b|a|r|\0|grbg|grbg|grbg...|
    // ----------------------------------
    cout<<name<<endl;
    // prints babbar.
    // does not print after null char

    for(char i:name){
        cout<<i;
    }
    cout<<endl;
    // prints all chars

    // we do not need to pass size of char arrayd to a function

    // cin vs getline
    // cin stops taking input on encountering first space, tab or new line
    // to get a multi-word string as input use get line
    // cin.getline(ste,length);
    // or
    // getline(cin,str);
    // changing default delimiter
    istream& getline(istream& input_stream, string& output, char delim);


    
    // char array functions
    // length
    int len=strlen(name);
    // compare
    strcmp(str1,str2);
    // returns 0 if matches
    // else return !=0

    // copy
    strcpy(destination. source);
    

    return 0;
}