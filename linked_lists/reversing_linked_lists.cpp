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
int main()
{
    vector<int> arr={1,2,3,4,9,6};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<6;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head);
    head=reverse(head);
    print(head);

    return 0;
}