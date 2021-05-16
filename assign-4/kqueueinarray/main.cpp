#include <iostream>

using namespace std;

struct kqueue{
    int size[50];
    int f[50];
    int r[50];
    int next[100];
    int elements[100];
    int e;
};

void enqueue(int x,struct kqueue &q,int n){

    if(q.e == -1){cout << "Queue is full" << endl;return;}

    int i = q.e;
    q.e = q.next[i];

    if(q.f[n] == -1){
        q.f[n] = i;
        q.r[n] = i;
    }
    else{
        q.next[q.r[n]] = i;
        q.next[i] = -1;
        q.r[n] = i;
    }
    q.elements[i] = x;
}

int dequeue(struct kqueue &q,int n){
    if(q.f[n] == -1){cout << "Queue is empty." << endl;return -1;}
    int i = q.f[n];
    q.f[n] = q.next[i];
    q.next[i] = q.e;
    q.e = i;

    return q.elements[i];
}


int main()
{
    cout << "Enter the number of queues" << endl;
    int k;
    cin >> k;
    struct kqueue q;
    for(int i=0;i<k;i++){
        q.f[i] = -1;
        q.r[i] = -1;
    }
    for(int i=0;i<99;i++){
        q.next[i] = i+1;
        q.next[99] = -1;
    }
    q.e = 0;

    enqueue(5,q,0);
    enqueue(6,q,1);
    enqueue(7,q,2);
    int x = dequeue(q,1);
    cout << x;
    int y = dequeue(q,0);
    cout << y;

    return 0;
}
