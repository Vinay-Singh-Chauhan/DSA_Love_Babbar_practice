#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)

// approach_1:
// time_complexity=O(n2)
void rotate_in_cycles(vvi &m ){
    int n=m.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int temp=m[i][j];
            m[i][j]=m[j][n-1-i];
            m[j][n-1-i]=m[n-1-i][n-1-j];
            m[n-1-i][n-1-j]=m[n-1-j][i];
            m[n-1-j][i]=temp;


        }
    }

}

// approach_2"
// time_complexity: O(n2)+O(n2)
void rotate_using_transpose(vvi &m){
    int n=m.size();
    // swap rows
    for(int j=0;j<n/2;j++){
        for(int i=0;i<n;i++){
            swap(m[i][j],m[i][n-1-j]);
        }
    }
    // transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(m[i][j],m[j][i]);
        }
    }
}
int32_t main()
{
    vvi matrix(4,vi(4));
    matrix={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    
    // solved for antic clockwise rotation
    // call
    rotate_using_transpose(matrix);
    
    // print
    for(auto i:matrix){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}