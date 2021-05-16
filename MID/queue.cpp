
#include<iostream>
using namespace std;
struct queue{
    int element[10][5];
    int cnt[10];
    int front;
    int rear;
};
void push(queue &q,int arr[],int k)
{
    if(q.rear==9)
        cout<<"queue overflow ";
    else
    {
        q.rear++;
        for(int i=0;i<k;++i)
            q.element[q.rear][i]=arr[i];
        q.cnt[q.rear]=k;
    }
}
void front(queue &q,int arr[])
{

    for(int i=0;i<q.cnt[q.front];++i)
        arr[i]=q.element[q.front][i];
}
void pop(queue &q)
{
    if(q.front==q.rear)
        cout<<"queue underflow";
    else
        q.front++;
}
int main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    for(int i=0;i<5;++i)
    {
        int count;
        cout<<"enter count";
        cin>>count;
        int arr[5],ar[5];
        for(int j=0;j<count;++j)
            cin>>arr[j];
        push(q,arr,count);
        if(i==3)
            pop(q);
        front(q,ar);
        for(int k=0;k<q.cnt[q.front];++k)
            cout<<ar[k]<<" ";
    }
    return 0;
}
