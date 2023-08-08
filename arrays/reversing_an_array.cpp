#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int size){
    int left=0,right=size-1;
    while(left<right){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    return;
}
int main()
{
        int arr[6]={1,2,3,4,5,6};
        reverse(arr,6);
        for(int i=0;i<6;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    return 0;
}