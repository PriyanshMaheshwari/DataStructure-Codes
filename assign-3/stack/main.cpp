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

int main()
{
    struct stack S;
    S.top = -1;
    S.size = 50;

    push(5,S);
    int x = peek(S);
    cout << x;
    int y = pop(S);
    cout << y;

    return 0;
}
