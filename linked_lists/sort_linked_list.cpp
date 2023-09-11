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
        
        cout<<"reached end"<<endl;
        return;
    }
    cout<<head->get_value()<<" ";
    print(head->get_next());
    return;
}
//! Not Working
void bubble_sort(Node** head,int len){
   Node** start;
   for(int i=0;i<len;i++){
    start=head;
    for(int j=0;j<len-i-1;j++){
        Node* first=*start;
        Node* second=first->get_next();
        if(first->get_value()>second->get_value()){
            Node* t=second->get_next();
            second->set_next(first);
            first->set_next(t);
            *start=second;
        }
        start=&(*start)->next;
    }

   }
}

//TODO Quick sort and merge sort
int main()
{
    vector<int> arr={1,5, 3, 2};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<4;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head);
    bubble_sort(&head,4);
    print(head);

    return 0;
}