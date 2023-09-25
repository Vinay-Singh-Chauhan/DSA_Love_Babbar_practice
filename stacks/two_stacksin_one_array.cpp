#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define umap unordered_map
#define fl(type,symbol,start,end) for(type symbol=start;symbol<end;symbol++)
#define pb(x) push_back(x)
class TwoStack{
    public:
    int sz,top1=-1,top2;
    int arr[1000];
    TwoStack(int sz){
        this->sz=sz;
        top2=sz;
    }
    void push1(int e){
        if(top1>=top2){
            cout<<"Overflow"<<endl;
        }
        top1++;
        arr[top1]=e;
    }
    void top_e1(){
        if(top1<=-1){
            cout<<"Underflow"<<endl;
        }else{
            cout<<arr[top1]<<endl;
        }
    }
    void pop1(){
        if(top1<=-1){
            cout<<"Underflow"<<endl;
        }else{
            top1--;
        }
    }
    bool is_empty1(){
        return top1==-1;
    }
    bool is_empty2(){
        return top2==sz;
    }
    void push2(int e){
        if(top1>=top2){
            cout<<"Overflow"<<endl;
        }
        top2--;
        arr[top2]=e;
    }
    void top_e2(){
        if(top2>=sz){
            cout<<"Underflow"<<endl;
        }else{
            cout<<arr[top2]<<endl;
        }
    }
    void pop2(){
        if(top2>=sz){
            cout<<"Underflow"<<endl;
        }else{
            top2++;
        }
    }
};
int32_t main()
{
    TwoStack st=TwoStack(10);
    st.push1(10);
    st.push1(20);
    st.top_e1();
    st.push1(30);
    st.pop1();
    st.top_e1();
    st.push1(10);
    st.top_e1();


    st.push2(10);
    st.push2(20);
    st.top_e2();
    st.push2(30);
    st.pop2();
    st.top_e2();
    st.push2(10);
    st.top_e2();
    return 0;
}