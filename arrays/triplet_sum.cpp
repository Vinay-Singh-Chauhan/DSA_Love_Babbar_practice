#include<iostream>
using namespace std;
void get_triplet_sum(int arr[],int size,int desiredsum){
    int i=0,j=1;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==desiredsum){
                    cout<<i<<" "<<j<< " "<<k<<endl;
                    return;
                    // return{i,j,k};
                }
            }
        }
    }
    cout<<"No Match Found"<<endl;
    
}
int main()
{
    int arr[100]={2,2,3,1,46,8};
    get_triplet_sum(arr,6,50);
    return 0;
}