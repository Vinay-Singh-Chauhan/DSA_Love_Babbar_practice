#include<bits/stdc++.h>
using namespace std;
#define ll long long
void optimized_bubble_sort(int arr[],int size);
int main()
{
    int arr[]={5,3,21,-43,0,6,-35,21,545,25};
    // bubble sort==================================
    int size=10;
    for(int i=0;i<size-1;i++){//! we can use i<size but there is no need for last iteration as there will be only one element which is always sorted.
        for(int j=1;j<size-i;j++){
            // bubbling out max element of unsorted array to its correct position.
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
    // optimized_bubble_sort(arr,size);
    // =============================================
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

//* space complexity : O(1)
//* time complexity : O(n^2)
//* Bubble Sort is a stable sorting algorithm. We swap elements only when A is less than B. If A is equal to B, we do not swap them, hence relative order between equal elements will be maintained.
//* Best time Complexity: O(N) 

//! Optimized Bubble Sort
void optimized_bubble_sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        bool swapped=false;
        for(int j=1;j<size-i;j++){
            if(arr[j]<arr[j-1]){
                swapped=true;
                swap(arr[j],arr[j-1]);
            }
        }
        // if zero swaps occur this means the array is now sorted and there is no need of any further iterations.
        if(!swapped){
            break;
        }
    }
}
