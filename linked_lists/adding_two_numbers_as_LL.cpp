// * Approach
// Reverse LL and add and then again reverse LL;
//! Additional Points
// 1, remember the case when both the LL are equal, they are added normally but there is a non zero carry present
// 2 handling carry
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
Node* add(Node* num1,Node* num2){
    num1=reverse(num1);
    num2=reverse(num2);

    int carry=0;
    Node *head=new Node(-1);
    Node *tail=head;
    while(num1 and num2){
        int a=num1->get_value();
        int b=num2->get_value();
        int res=a+b+carry;
        carry=res/10;
        res%=10;
        Node* elem = new Node(res);
        tail->set_next(elem);
        tail=tail->get_next();
        num1=num1->get_next();
        num2=num2->get_next();
    }
    while(num1){
        int a=num1->get_value();
        int res=a+carry;
        carry=res/10;
        res%=10;
        Node* elem = new Node(res);
        tail->set_next(elem);
        tail=tail->get_next();
        num1=num1->get_next();
        
    }
    while(num2){
        int a=num2->get_value();
        int res=a+carry;
        carry=res/10;
        res%=10;
        Node* elem = new Node(res);
        tail->set_next(elem);
        tail=tail->get_next();
        num2=num2->get_next();
    }
    if(carry!=0){
        Node* elem = new Node(carry);
        tail->set_next(elem);
        tail=tail->get_next();
    }
    Node* dummy=head;
    head=head->get_next();
    dummy->set_next(nullptr);
    delete dummy;
    head=reverse(head);
    return head;
}
int main()
{
    vector<int> arr={ 4,5,0};
    vector<int> arr2={3,4,5};
    Node* head1=new Node(arr[0]);
    Node* temp=head1;
    Node* head2=new Node(arr2[0]);
    for(int i=1;i<3;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    temp=head2;
    for(int i=1;i<3;i++){
        Node*a= new Node(arr2[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head1);
    print(head2);
    Node* h=add(head1,head2);
    print(h);
    return 0;
}