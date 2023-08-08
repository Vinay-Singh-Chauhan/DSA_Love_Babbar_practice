#include<bits/stdc++.h>
using namespace std;
//** setting precision
    // use setPrecision(no of digits after floating point) 
double morePrecision(int temp,int precision,int n){
    double factor=1,ans=temp;
    for(int i=1;i<=precision;i++){
        factor/=10;
        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n=37;
    double l=0,r=n,ans=0;
    // --------------------------------------------------
    //      My solution 
    // double precision=0.0001;
    // while(l<=r){
    //     double m=l+(r-l)/2;
    //     if(m*m ==n){
    //         ans=m;
    //         break;
    //     }else if(m*m > n){
    //         r=m-precision;
    //     }else{
    //         ans=m;
    //         l=m+precision;
    //     }

    // }
    // --------------------------------------------------

    // Love Babbar solution
    int s=0,e=n; 
    long long tempsolution=0;;
    while(s<=e){
         long long int m=s+(e-s)/2;
         if(m*m > n){
            e=m-1;
        }else{
            tempsolution=m;
            s=m+1;
        }

    }
    double final_solution=0;
    final_solution=morePrecision(tempsolution,4,n);
    cout<<final_solution<<endl;
    return 0;
}