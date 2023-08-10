// priority queues are and used for max heaps and min heaps
// default priority queue is max heap

#include<iostream>
#include<queue>
using namespace std;
int main(){
    // max heap-- largest element at top
    priority_queue<int>pq;
    // min heap-- smallest element at top
    priority_queue<int,vector<int>,greater<int>>pq2;

    pq.push(1);
    pq.push(2);

    pq.size();
      
    pq.top();

    pq.pop();

    pq.empty();



}