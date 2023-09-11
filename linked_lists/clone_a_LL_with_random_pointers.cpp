//* Approaches
// 1: Brute Force: first clone LL using next pointers and then for each original node calculate its random pointer distance from head and implement it in copied list.
// TC:O(N2)
// SC:O(1)

// 2. half optimised: use a map to store a corresponding old-new node mapping so that we get new->random= mp[corresponding_old->random]
// TC:O(N)
// SC:O(N)

// 3. Fully Optimised : create a zigzag list that is old->corresponding_new->old_next->corresponding_new->old_next->....
// TC:O(N)
// SC:O(1)

//! there is change in Node structure for this question
#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int val;
        Node* next;
        Node* arb;//arbitary
    public:
        Node(){}
        Node(int val){
            this->val=val;
            this->next=nullptr;
            this->arb=nullptr;
        }
        Node(int val,Node* next){
            this->val=val;
            this->next=next;
            this->arb=nullptr;
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
        Node* get_arb(){
            return this->arb;
        }
        void set_arb(Node* ptr){
            this->arb=ptr;
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

int main()
{
    // input
    vector<int> arr={1,2,3,4,5};
    Node* head=new Node(arr[0]);
    Node* tmp=head;
    for(int i=1;i<5;i++){
        Node*a= new Node(arr[i]);
        tmp->set_next(a);
        tmp=tmp->get_next();
    }
    tmp=head;
    tmp->set_arb(tmp->get_next()->get_next());//1
    tmp=tmp->get_next();
    tmp->set_arb(head);//2
    tmp=tmp->get_next();
    tmp->set_arb(tmp->get_next()->get_next());//3
    tmp=tmp->get_next();
    tmp->set_arb(head->get_arb());//4
    tmp=tmp->get_next();
    tmp->set_arb(head->get_next());//5

    // construct clone LL without random pointers
    tmp=head;
    Node* clone_head=new Node(-1);
    Node* clone_tail= clone_head;
    while(tmp!=nullptr){
        Node* a=new Node(tmp->get_value());
        clone_tail->set_next(a);
        clone_tail=clone_tail->get_next();
        tmp=tmp->get_next();
    }
    Node *dummy=clone_head;
    clone_head=clone_head->get_next();
    dummy->set_next(nullptr);
    delete dummy;

    // change next links;
    tmp=head;
    Node* ct=clone_head;
    while(tmp){
        Node* org_next=tmp->get_next();
        Node* clone_next=ct->get_next();
        tmp->set_next(ct);
        tmp=org_next;
        ct->set_next(tmp);
        ct=clone_next;
    }

    // setting random pointers
    tmp=head;
    ct=clone_head;
    while(ct and tmp){
        Node * new_random=tmp->get_arb()->get_next();
        ct->set_arb(new_random);
        ct=ct->get_next();
        if(!ct) break;
        ct=ct->get_next();
        tmp=tmp->get_next()->get_next();
    }

    // undo change in links
    tmp=head;
    ct=clone_head;
    while(tmp and ct){
        tmp->set_next(tmp->get_next()->get_next());
        if(ct->get_next())
        ct->set_next(ct->get_next()->get_next());   
        else
        ct->set_next(nullptr);
        tmp=tmp->get_next();
        ct=ct->get_next();
    }

    // verify
    cout<<"verifying next links"<<endl;
    print(head);
    print(clone_head);
    cout<<"verifying arbitary links"<<endl;
    tmp=head;
    ct=clone_head;
    while(tmp){
        cout<<tmp->get_arb()->get_value()<<" == "<<ct->get_arb()->get_value()<<endl;
        ct=ct->get_next();
        tmp=tmp->get_next();
    }

}