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

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}

class kQueues{
    public:
        int n;
        int k;
        int* next;
        int* rear;
        int* front;
        int* arr;
        int freespot;
        kQueues(int n,int k){
            this->n=n;
            this->k=k;
            arr=new int[n];
            next=new int[n];
            rear=new int[k];
            front=new int[k];
            for(int i=0;i<k;i++){
                front[i]=-1;
                rear[i]=-1;
            }
            for(int i=0;i<n;i++) next[i]=i+1;
            next[n-1]=-1;
            freespot=0;
        }
        void enqueue(int val,int qn){
           //overflow condition
           if(freespot==-1) {
            cout<<"OverFlow";
            return;
           } 
           //first free index
            int index=freespot;
            //  update freespot
            freespot=next[index];

           //first element
           if(front[qn-1]==-1){
                front[qn-1]=index;
           }
           else{
            //link new element to prev element
            next[rear[qn-1]]=index;
           }
            //update next 
            next[index]=-1;
            //update rear
            rear[qn-1]=index;
            //push
            arr[index]=val;
        }
        void pop(int qn){
            // underflow
            if(front[qn-1]==-1) return;
            
            int index=front[qn-1];
            front[qn-1]=next[index];
            //freespot
            next[index]=freespot;
            freespot=index;
        }
};
int32_t main()
{
    int test_case;
    cin>>test_case;
    for(int test_c=0;test_c<test_case;test_c++){
        
        }
    return 0;
}