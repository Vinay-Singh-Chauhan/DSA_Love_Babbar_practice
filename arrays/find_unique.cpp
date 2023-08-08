#include<iostream>
using namespace std;
int find_unique(int arr[],int size){
    int frequency_arr[100]={0};
    for(int i=0;i<size;i++){
        frequency_arr[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        if(frequency_arr[i]==1){
            return i;
        }
    }
    return -1;
}

// if all non-unique elements are present even no. of times.
int find_unique_using_xor(int arr[],int size){
    int elem=arr[0];
    for(int i=1;i<size;i++){
        elem=elem xor arr[i];
    }
    return elem;
}
int main()
{
    int arr[100]={1,1,3,3,1,12,1,1,1,1,1,1};
    int n=12;
    cout<<find_unique(arr,12);
    
    return 0;
}