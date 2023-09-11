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

void sort_012(Node * &head){
    if(head==nullptr){
        return ;
    }
    Node* zeroes= new Node(0,nullptr);
    Node* zeroTail= zeroes;

    Node* ones= new Node(0,nullptr);
    Node* oneTail= ones;

    Node* twos= new Node(0,nullptr);
    Node* twoTail= twos;

    Node* tmp=head;

    while(tmp){
        if(tmp->get_value()==0){
            zeroTail->set_next(tmp);
            zeroTail=zeroTail->get_next();
        }
        if(tmp->get_value()==1){
            oneTail->set_next(tmp);
            oneTail=oneTail->get_next();
        }
        if(tmp->get_value()==2){
            twoTail->set_next(tmp);
            twoTail=twoTail->get_next();
        }
            tmp=tmp->get_next();
    }
    if(zeroes->get_next()){
        head=zeroes->get_next();
    }
    if(ones->get_next()){
        zeroTail->set_next(ones->get_next());
    }
    if(twos->get_next()){
        oneTail->set_next(twos->get_next());
    }
    twoTail->set_next(nullptr);
    twos->set_next(nullptr);
    ones->set_next(nullptr);
    zeroes->set_next(nullptr);
    delete twos,ones,zeroes;
}

int main()
{
    vector<int> arr={1,0,0,2,2,1,0};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<7;i++){
        Node*a= new Node(arr[i]);
        temp->set_next(a);
        temp=temp->get_next();
    }
    print(head);
    sort_012(head);
    print(head);
    return 0;
}