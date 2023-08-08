#include<bits/stdc++.h>
using namespace std;
bool required_students(int pages,int books[],int students,int sz){
    long long st=1;
    long long curr=0;
    long long no_books=sz;
    for(long long i=0;i<no_books;i++){
        if(books[i]>pages){
            return false;
        }
       if(curr+books[i]>pages){
            st++;
            curr=0;
       }
       curr+=books[i];

    }
    return st<=students;
}
// N is size of array
// M is no of students

long long findPages(int books[], int N, int M) 
    {
        long long l=0,r=INT_MAX;
        long long ans=-1;
        if(M==N){
            return *max_element(books,books+N);
        }
        else if(N<M){
            return -1;
        }
        while(l<=r){
            long long m=l+(r-l)/2;
            if(required_students(m,books,M,N)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }


int main()
{
    // cout<<findPages()
    return 0;
}