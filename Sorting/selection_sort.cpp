#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int> arr={5,3,21,-35,0,6,-43,21,545,25};
    // selection sort==================================
    int size=arr.size();
    for(int i=0;i<size-1;i++){//! u can use [i<size] also but since at this stage only one element is remaining it will be sorted already.
        // to store index of minimum element in unsorted array
        int min_idx=i;
        // selecting minimum element of unsorted array
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        // putting min_idx element to its correct position
        swap(arr[min_idx],arr[i]);
    }
    // =============================================
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

//* space complexity : O(1)
//* time complexity : O(n^2)
//* It is not a stable algorithm, because it swaps non-adjacent elements. But it can be modified into a stable algorithm.
//* Best time Complexity: O(N^2) 


// ! Stable Selection Sort

void stableSelectionSort(int a[], int n)
{
    // Iterate through array elements
    for (int i = 0; i < n - 1; i++)
    {
 
        // Loop invariant : Elements till a[i - 1]
        // are already sorted.
 
        // Find minimum element from
        // arr[i] to arr[n - 1].
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
 
        // Move minimum element at current i.
        int key = a[min];
      //Shift left all elements by one.
      for(int k=min;k>i;k--)
        a[k]=a[k-1];
      //Store the key at its right position.
        a[i] = key;
    }
}