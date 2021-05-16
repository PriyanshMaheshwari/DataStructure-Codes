#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(int x,struct queue &q){
    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.elements[q.r] = x;
}

int dequeue(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    int t = q.elements[q.f];
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.f = (q.f+1)%q.size;
    }
    return t;
}

struct stack{
    struct queue q;
};

void push(int x,struct stack &S){
    int s = S.q.r-S.q.f+1;
    if(S.q.f == -1){s = 0;}
    if(s<0){s = S.q.size-s-1 ;}

    if(s == S.q.size){cout << "Stack is full." << endl; return;}

    enqueue(x,S.q);

    int i=0;
    while(i<s){
        enqueue(dequeue(S.q),S.q);
    }
}

int pop(struct stack &S){
    if(S.q.f == -1){cout << "Stack is empty ." << endl;return -1;}
    return dequeue(S.q);
}

int main()
{
    struct stack S;

    S.q.size = 30;
    S.q.f = -1;S.q.r = -1;

    push(5,S);
    int x = pop(S);
    cout << x;

    return 0;
}
