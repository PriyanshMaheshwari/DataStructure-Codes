#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
struct btnode{
    int data;
    struct btnode *lc;
    struct btnode *rc;
};
typedef btnode* BTPTR;
void make(BTPTR &T)
{
   cout<<"enter no: ";
   int x;
   cin>>x;
   if(x!=0)
   {
       BTPTR t=new struct btnode;
       t->data=x;
       t->lc=NULL;
       t->rc=NULL;
       T=t;
       cout<<"want left y/n: ";
       char ch;
       cin>>ch;
       if(ch=='y')
        {
            cout<<"enter left of"<< T->data<<endl;
            make(T->lc);
        }
        cout<<"enter right of "<< T->data<<endl;
        make(T->rc);
   }
}
void ancestor_print(BTPTR T,int k)
{
    stack<BTPTR>s;
    stack<int>s1;
    int arr[50];
    s.push(T);
    s1.push(-1);
    int i;
    int flag=1;
    while(flag==1&&!s.empty())
    {
        BTPTR t=s.top();s.pop();
        i=s1.top()+1;s1.pop();
        while(t!=NULL)
        {
            arr[i]=t->data;
            if(t->data==k)
            {
                flag=0;
                break;
            }
            else
            {
                if(t->rc!=NULL)
                {
                    s.push(t->rc);
                    s1.push(i);
                }
                 i++;
            }
            t=t->lc;
        }
    }
    for(int j=0;j<i;++j)
        cout<<arr[j]<<" ";
}
int main()
{
    BTPTR T=NULL;
    make(T);
    int k;
    cout<<"Enter k: ";
    cin>>k;
    ancestor_print(T,k);
    return 0;
}
