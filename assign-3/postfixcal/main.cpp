#include <iostream>
#include <cstring>
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

int sol(int a,int b,char x){
    switch(x){
    case '+' :
        return a+b ;
    case '-' :
        return b-a;
    case '*' :
        return b*a;
    case '/' :
        return b/a;
    }
}

int main(){
    struct stack S;
    S.top = -1;
    S.size = 50;

    cout << "Enter the expression." << endl;
    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c!='+' && c!='-' && c!='*' && c!='/'){
            push(s[i] - '0',S);
        }
        else{
            int x = pop(S);
            int y = pop(S);
            push(sol(x,y,s[i]),S);
        }
    }

    cout << S.element[S.top] << endl;

    return 0;
}
