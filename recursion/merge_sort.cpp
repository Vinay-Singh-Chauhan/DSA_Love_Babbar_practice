#include<iostream>
using namespace std;

void merge(int arr[],int start,int end,int mid){
    int length_1=mid-start+1;
    int length_2=end-mid;
    int arr_1[length_1],arr_2[length_2];

    for(int i=0;i<length_1;i++){
        arr_1[i]=arr[start+i];
    }
    
    for(int i=0;i<length_2;i++){
        arr_2[i]=arr[mid+1+i];
    }

    // cout<<mid-start+1<<" --==-- "<<end-mid<<endl;
    // for(int i:arr_1){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    int i=0,j=0,k=start;
    while(i<length_1 and j<length_2){
        if(arr_1[i]<arr_2[j]){
            arr[k]=arr_1[i];
            i++;
        }else{
            arr[k]=arr_2[j];
            j++;
        }
        k++;
    }
    while(i<length_1){
        arr[k]=arr_1[i];
        i++;
        k++;
    }
    while(j<length_2){
        arr[k]=arr_2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,end,mid);
}
int main()
{
    int arr[10]={2,4,546,8,7972,1,3435,654,33421,5656};
    merge_sort(arr,0,9);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}


// * Time complexity : O(nlogn)
// * Space Complexity: O(N)
// * Stable
