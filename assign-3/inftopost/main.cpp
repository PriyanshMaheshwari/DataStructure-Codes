#include <iostream>

using namespace std;

struct stack{
    char element[50];
    int size;
    int top;
};

void push(char x,struct stack &S){
    if(S.top == S.size){cout << "The stack is full." << endl;}
    else{
        S.top++;
        S.element[S.top] = x;
    }
}

char pop(struct stack &S){
    if(S.top == -1){cout << "The stack is empty" << endl;return -1;}
    else{
        return S.element[S.top--];
    }
}

char peek(struct stack &S){
    if(S.top == -1){cout << "The stack is empty" << endl;return -1;}
    else{
        return S.element[S.top];
    }
}

void sol(char c,struct stack &S){
    switch(c){
    case ')' :
        while(peek(S) != '('){cout << pop(S);}
        pop(S);
        break;

    case '(' :
        push(c,S);
        break;

    case '*' :
        if(peek(S) == '*' || peek(S) == '/'){cout << pop(S);}
        push(c,S);
        break;

    case '/' :
        if(peek(S) == '*' || peek(S) == '/'){cout << pop(S);}
        push(c,S);
        break;

    case '+' :
        while(peek(S) == '*' || peek(S) == '/' || peek(S) == '+' || peek(S) == '-'){cout << pop(S);}
        push(c,S);
        break;

    case '-' :
        while(peek(S) == '*' || peek(S) == '/' || peek(S) == '+' || peek(S) == '-'){cout << pop(S);}
        push(c,S);
        break;
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
        if(c!='+' && c!='-' && c!='*' && c!='/' && c!='(' && c!=')'){
            cout << s[i];
        }
        else{
            if(S.top == -1){push(s[i],S);continue;}
            sol(s[i],S);
        }
    }

    while(S.top != -1){cout << pop(S);}

    return 0;
}
