#include<bits/stdc++.h>
using namespace std;
void reverse_in_pairs(int arr[],int size){
    int right=1;
    while(right<size){
        int left=right-1;
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        right+=2;
    }
    return;
}
int main()
{
        int arr[5]={1,2,3,4,5};
        reverse_in_pairs(arr,5);
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    return 0;
}