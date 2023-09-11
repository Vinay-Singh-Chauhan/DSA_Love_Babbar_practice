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
pair<Node*,Node*> divide_list(Node* &head ,unordered_map<Node* ,bool> &mp){
    
    if(head==nullptr||head->get_next()==nullptr){
        return{nullptr,nullptr};
    }
    
    Node* dummy=new Node(0,head);
    Node* slow=dummy;
    Node* fast=dummy;

    while(fast!=nullptr and slow!=nullptr){
        if(mp[fast->get_next()]){
            //processing
            Node* head1=head;
            Node* head2=slow->get_next();
            slow->set_next(head);
            // part one of the cll is done
            Node* tmp=head2;
            while(tmp->get_next()!=head){
                tmp=tmp->get_next();
            }
            tmp->set_next(head2);
            // delete dummy;
            return {head1,head2};
        }
        fast=fast->get_next();
        mp[fast]=true;
        if(fast!=nullptr){
            fast=fast->get_next();
            mp[fast]=true;
        }
        slow=slow->get_next();
    }
    // delete dummy;
    return {nullptr,nullptr};
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    temp->set_next(head);
    // print(head);
    unordered_map<Node*,bool>mp;
    pair<Node*, Node*>p=divide_list(head,mp);

    // print(head);
    print(p.first);
    // print(p.second);

    return 0;
}