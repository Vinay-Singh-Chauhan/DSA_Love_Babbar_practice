#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int> arr={5,3,21,-35,0,6,-43,21,545,25};
    // insertion sort==================================
    int size=arr.size();
    // we do not start with i=0 because a single element is always sorted.
    for(int i=1;i<size;i++){
        int elem=arr[i];
        int j=i-1;
        for(j=i-1;j>=0;j--){
            if(arr[j]>elem){
               arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=elem;
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
//* Insertion sort is a stable algorithm, because it keeps the order of equal elements same. We are shifting elements not swapping.
//* Best time Complexity: O(N) 
