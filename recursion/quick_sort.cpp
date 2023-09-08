#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot_elem=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot_elem){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quick_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int pivot=partition(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);
}
int main()
{
    int arr[10]={2,4,546,8,7972,1,3435,654,33421,5656};
    quick_sort(arr,0,9);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}


// * Time complexity : O(n^2), Theta(nlogn)
// * Space Complexity: O(N)
// * Not Stable
