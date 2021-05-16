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

void rev(struct stack &S){
    if(S.top == -1){return ;}

    int t = pop(S);
    rev(S);
    cout << t << " ";
}

int main()
{
    struct stack S;
    S.top = -1;
    S.size = 50;

    cout << "Give the entries, press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x==-1){break;}
        push(x,S);
    }

    rev(S);

    return 0;
}
