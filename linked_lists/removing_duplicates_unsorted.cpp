// * approach
// 1: head and cur pointer: for every node traverse remaining list and remove nodes with same value
//  tc: O(N2)
//  sc: O(1)

// 2: sort Linked list and apply remove_duplicates_sorted_algo

// 3:use map: keep a map of visited and traverse linedlist and if at any instance a visited value comes remove it

// store unique elements and create a new linkedlist

#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
        int val;
        Node* next;
    public:
        Node(){}
        Node(int val){
            this->val=val;
            this->next=nullptr;
        }
        Node(int val,Node* next){
            this->val=val;
            this->next=next;
        }
        int get_value(){
            return this->val;
        }
        Node *get_next(){
            return this->next;
        }
        void set_next(Node* ptr){
            this->next=ptr;
        }
        void set_value(int val){
            this->val=val;
        }
        ~Node(){
            if(this->next!=nullptr){
                delete this->next;
            }
            this->next=nullptr;
        }
};
void print(Node* head){
    if(head==nullptr){
        cout<<endl;
        return;
    }
    cout<<head->get_value()<<" ";
    print(head->get_next());
    return;
}
void remove_duplicates(Node * & head,unordered_map<int,bool> &mp){
    Node* tmp=head;

    while(tmp!=nullptr and tmp->get_next()!=nullptr){
        mp[tmp->get_value()]=true;
        if(mp[tmp->get_next()->get_value()]==true){
            Node *todelete=tmp->get_next();
            tmp->set_next(todelete->get_next());
            todelete->set_next(nullptr);
            delete todelete;
        }
        else{
            
            tmp=tmp->get_next();
        
        }
    }
}
int main()
{
    vector<int> arr={1,2,3,4,9,6,6,6,6,7,8,4,4,4,89,89};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head);
    unordered_map<int,bool>mp;
    remove_duplicates(head,mp);
    print(head);

    return 0;
}