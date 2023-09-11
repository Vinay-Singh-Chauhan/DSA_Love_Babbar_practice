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
Node * get_mid(Node* head){
    if(!head) return head;
    Node* slow=head;
    Node* fast=head->get_next();
    while(fast and fast->get_next()){
        slow=slow->get_next();
        fast=fast->get_next();
        if(!fast) break;
        fast=fast->get_next();
    }
    return slow;
}
Node* merge(Node* left,Node* right){
    if(!left) return right;
    if(!right) return left;
    Node* dummy=new Node(-1);
    Node* tmp=dummy;
    while(left and right){
        if(right->get_value()<left->get_value()){
            tmp->set_next(right);
            right=right->get_next();
        }else{
            tmp->set_next(left);
            left=left->get_next();
        }
        tmp=tmp->get_next();
    }
    while(left){
        tmp->set_next(left);
        left=left->get_next();
        tmp=tmp->get_next();
    }
    while(right){
        tmp->set_next(right);
        right=right->get_next();
        tmp=tmp->get_next();
    }
    tmp=dummy->get_next();
    dummy->set_next(nullptr);
    delete dummy;
    return tmp;

}
Node* merge_sort(Node* &left){
    if(!left || !left->get_next()) return left;
    Node* mid=get_mid(left);
    Node* right=nullptr;
    if(mid){
        right=mid->get_next();
        mid->set_next(nullptr);
    }
    left=merge_sort(left);
    right=merge_sort(right);

    left=merge(left,right);
    return left;
}
int main()
{
    vector<int> arr={ 4};
    Node* head1=new Node(arr[0]);
    Node* temp=head1;
    for(int i=1;i<1;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    merge_sort(head1);
    print(head1);
    return 0;
}