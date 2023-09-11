//* Approach
// 1: create array and check 
// TC:O(N) SC=O(N)

// 2: reverse entire LL and compare both 
// TC:O(N) SC=O(N)

// 3: get middle of LL and reverse next half. Now compare first and second halves if equal then palindrome 
// TC:O(N) SC=O(1)

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
Node* reverse(Node* &head){
    Node* prev=nullptr;
    Node *curr=head;
    Node *next=nullptr;
    while(curr!=nullptr){
        next=curr->get_next();
        curr->set_next(prev);
        prev=curr;
        curr=next;
    }
    // curr->get_value();
    return prev;
}
bool check_palindrome(Node* head){
    if(!head || head->get_next()==nullptr) return true;
    Node* slow=head;
    Node* fast=slow->get_next();
    while(fast!=nullptr and fast->get_next()!=nullptr){
        slow=slow->get_next();
        fast=fast->get_next();
        if(!fast) break;
        fast=fast->get_next();
    }
    Node* head2=slow->get_next();
    head2=reverse(head2);
    slow->set_next(head2);
    fast=slow->get_next();
    slow=head;
    while(slow and fast){
        if(slow->get_value()!=fast->get_value()){
            return false;
        }
        slow=slow->get_next();
        fast=fast->get_next();
    }
    return true;
}
int main()
{
    // TODO
     vector<int> arr={ 1,5,1};
    
    Node* head1=new Node(arr[0]);
    Node* temp=head1;
    for(int i=1;i<3;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head1);
    bool f=check_palindrome(head1);
    print(head1);
    cout<<f<<endl;
    return 0;
}