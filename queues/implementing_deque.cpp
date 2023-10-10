#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
int32_t main()
class deque{
    public:
    int size,front=-1,rear=-1;
    int* arr=nullptr;
    deque(int n){
        size=n;
        arr=new int[size];
    }
    int push_front(int elem){
        // check if deque is full
        if((front==0 and rear==size-1)||(rear==(front-1)%(size-1))){
            return -1;
        }
        // first element
        if(front==-1){
            front=rear=0;
        }
        else if(front ==0 and rear!=size-1){
            front = size-1;
        }
        else {
            front--;
        }
        arr[front]=elem;
        return elem;
    }
    int push_back(int elem){
        // check if deque is full
        if((front==0 and rear==size-1)||(rear==(front-1)%(size-1))){
            return -1;
        }
        // first element
        if(rear==-1){
            front=rear=0;
        }
        else if(rear ==size-1 and front!=0){
            rear=0;
        }
        else {
            rear++;
        }
        arr[rear]=elem;
        return elem;
    }
    int pop_front(){
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front ==rear) front =rear=-1;
        else if (front==size-1) front=0;
        else front++;
        return ans;

    }
    int pop_back(){

        if(rear==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front ==rear) front =rear=-1;
        else if (rear==0) rear=size-1;
        else rear--;
        return ans;
    }
    int get_front(){
        if((front==0 and rear==size-1)||(rear==(front-1)%(size-1))){
            return -1;
        }
        return arr[front];
    }
    int get_rear(){
        if((front==0 and rear==size-1)||(rear==(front-1)%(size-1))){
            return -1;
        }
        return arr[rear];
    }
    bool is_full(){
        if((front==0 and rear==size-1)||(rear==(front-1)%(size-1))){
            return true;
        }
        return false;
    }
    bool is_empty(){
        return front==-1 ;
    }
}
{
    
    return 0;
}