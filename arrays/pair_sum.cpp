#include<iostream>
using namespace std;
void get_pair_sum(int arr[],int size,int desiredsum){
    int i=0,j=1;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(arr[j]==desiredsum-arr[i]){
                cout<<i<<" "<<j<<" "<<endl;
                return;
            }
        }
    }
    cout<<"No Match Found"<<endl;
    
}
int main()
{
    int arr[100]={1,2,1,1,46,8};
    get_pair_sum(arr,6,50);
    return 0;
}