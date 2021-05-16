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

    cout << "Enter the sequence." << endl;
    int a[6];
    for(int i=0;i<6;i++){
        cin >> a[i];
    }

    int j = 0;

    for(int i=0;i<6;i++){
        push(i+1,S);
        while(S.top!=-1 && a[j]==peek(S)){int x = pop(S);j++;}
    }

    if(S.top == -1){cout << "TRUE" << endl;}
    else{cout << "FALSE" << endl;}
    return 0;
}
