#include<iostream>
using namespace std;
// if you want to restrict result to have only unique elems then update matched location in second array by a differen number.
// also can use set or freq

// first approach
void find_intersection(int arr1[],int size1,int arr2[],int size2){
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                break;//to restrict multiple matches of same ith to multiple jth 
            }
        }
    }
    cout<<endl;
    return;
}

// for leetcode 349

void find_intersection(int arr1[],int size1,int arr2[],int size2,bool vis[]){
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(vis[arr1[i]]==false and arr1[i]==arr2[j]){
                vis[arr1[i]]=true;
                cout<<arr1[i]<<" ";
                break;//to restrict multiple matches of same ith to multiple jth 
            }
        }
    }
    cout<<endl;
    return;
}

int main()
{
    //for leet code...............
    bool vis[1001];
    for(auto &i:vis){
        i=false;
    }
    //.................
    int arr1[100]={1,2,3,4,5,6};
    int arr2[100]={9,8,5,1,3,4,5};
    int n1=6,n2=7;
    find_intersection(arr1,n1,arr2,n2);
    leetcode_find_intersection(arr1,n1,arr2,n2,vis);
    return 0;
}