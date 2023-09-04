#include<bits/stdc++.h>
using namespace std;
void spiral_print(int arr[][4],int n,int m){
    int row_start=0,row_end=n-1,col_start=0,col_end=m-1,row=0,col=0;
    int count =0,total_elements=n*m;
    while(count<total_elements){
        for(col=col_start;count<total_elements and col<=col_end;col++){
            cout<<arr[row][col]<<" ";
            count++;
        }
        col--;
        row_start++;
        for(row=row_start;count<total_elements and row<=row_end;row++){
            cout<<arr[row][col]<<" ";
            count++;
        }
        row--;
        col_end--;
        for( col=col_end;count<total_elements and col>=col_start;col--){
            cout<<arr[row][col]<<" ";
            count++;
        }
        col++;
        row_end--;
        for( row=row_end;count<total_elements and row>=row_start;row--){
            cout<<arr[row][col]<<" ";
            count++;
        }
        row++;
        col_start++;
    }
    cout<<endl;
    
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    spiral_print(arr,n,m);
    return 0;
}