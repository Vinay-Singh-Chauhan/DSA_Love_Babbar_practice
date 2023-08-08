#include<iostream>
using namespace std;
int find_unique(int arr[],int size){
    int frequency_arr[100]={0};
    for(int i=0;i<size;i++){
        frequency_arr[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        if(frequency_arr[i]>1){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[100]={1,2,3,4,5,6,7,8,9,3};
    int n=10;
    cout<<find_unique(arr,n);
    
    return 0;
}