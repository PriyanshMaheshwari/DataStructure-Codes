#include <iostream>

using namespace std;

struct stack{
    int element[50];
    int size;
    int top;
};

void push(int x,struct stack &S){
    if(S.top == S.size){cout << "The stack is full." << endl;}
    else{
        S.top++;
        S.element[S.top] = x;
    }
}

int pop(struct stack &S){
    if(S.top == -1){cout << "The stack is empty" << endl;return -1;}
    else{
        return S.element[S.top--];
    }
}

int peek(struct stack &S){
    if(S.top == -1){cout << "The stack is empty" << endl;return -1;}
    else{
        return S.element[S.top];
    }
}

struct queue{
    struct stack S;
};

void enqueue(int x,struct queue &q){
    if(q.S.top == q.S.size){cout << "Queue is full." << endl;return;}
    else{
        struct stack temp;
        temp.size = q.S.size;
        temp.top = -1;

        while(q.S.top != -1){
            push(pop(q.S),temp);
        }
        push(x,q.S);
        while(temp.top != -1){
            push(pop(temp),q.S);
        }
    }
}

int dequeue(struct queue &q){
    if(q.S.top == -1){cout << "Queue is empty." << endl;return -1;}
    else{return pop(q.S) ;}
}

int main()
{
    struct queue Q;
    Q.S.size = 30;
    Q.S.top = -1;

    enqueue(5,Q);
    int x = dequeue(Q);
    cout << x << endl;
    dequeue(Q);

    return 0;
}
