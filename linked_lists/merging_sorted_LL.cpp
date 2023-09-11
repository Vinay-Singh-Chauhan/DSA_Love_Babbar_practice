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

Node* merge(Node * &head1,Node* &head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    Node* h1=head1;
    Node* h2=head2;
    // if h1 has only one element
    if(h1->get_next()==nullptr){
        head1->set_next(h2);
        return head1;
    }
    while(h1->get_next()!=nullptr and h2!=nullptr){
        // if h2>h1 then swap
        if((h1->get_value() <= h2->get_value()) and (h2->get_value() <= h1->get_next()->get_value()) ){

            Node *t = h1->get_next();
            Node* tt=h2->get_next();
            h1->set_next(h2);
            h2->set_next(t);
            h2=tt;
        }
        else{
            h1=h1->get_next();
            if(h1->get_next()==nullptr){
                h1->set_next(h2);
                return head1;
            }
        }
        
    }
    return head1;
}

int main()
{
    vector<int> arr={1,3,5,7,9};
    vector<int> arr2={0,4,6,8};
    Node* head1=new Node(arr[0]);
    Node* temp=head1;
    Node* head2=new Node(arr2[0]);
    for(int i=1;i<5;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    temp=head2;
    for(int i=1;i<4;i++){
        Node*a= new Node(arr2[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head1);
    print(head2);
    if(head1->get_value()<head2->get_value()){
        head1=merge(head1,head2);
    }else{
        head1=merge(head2,head1);
    }
    print(head1);
    return 0;
}