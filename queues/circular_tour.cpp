#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
int gcd( int a,  int b)
{
    if (b == 0)
    return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
// * My approach -- works
// int32_t main()
// {
    
//     vi petrol={4,6,7,4};
//     vi dist={6,5,3,5};
//     vi possible_starts;
//     int n=4;
//     fl(int,i,0,n){
//         if(petrol[i]>dist[i])
//         possible_starts.push_back(i);
//     }
//     for(auto st:possible_starts){
//         int sum=0;
//         bool reached=true;
//         for(int i=st;i<n;i++){
//             sum+=petrol[i];
//             sum-=dist[i];
//             if(sum<0){
//                 reached=false;
//                 break;
//             }
//         }
//         for(int i=0;i<st;i++){
//             sum+=petrol[i];
//             sum-=dist[i];
//             if(sum<0){
//                 reached=false;
//                 break;
//             }
//         }
//         if(reached){
//             cout<<st<<endl;
//             break;
//         }
//     }
//     return 0;
// }
struct petrolPump{
    int petrol;
    int distance;
};
//! to see what is going wrong in this code;

int tour(petrolPump p[],int n)
    {
    int front=0,rear=0;
    bool flag=true;
    while(front<n){
        int balance=0;
        while(balance>=0 and rear<n){
            balance+=(p[rear].petrol-p[rear].distance);
            if(balance>=0){
                rear++;
                rear%=n;
            }else{
                break;
            }
            if(front==rear){
                return front;
                break;
            }
        }
        if(balance<0){
            front=rear+1;
            rear=front;
        }
        if(front>=n){
            break;
        }
        rear=rear%n;
        front=front%n;
        
    }
    if(front==n){
        return -1;
    }else{
        return front;
    }
}

// * most optimized code
int tour(petrolPump p[],int n){
    int deficit=0,balance=0,start=0;
    for(int i=0;i<n;i++){
        balance+=(p[i].petrol-p[i].distance);
        if(balance<0){
            start=i+1;
            deficit+=balance;
            balance=0;
        }
    }
    if(balance+deficit>=0){
        return start;
    }
    return -1;
}
int32_t main(){
    
    

}