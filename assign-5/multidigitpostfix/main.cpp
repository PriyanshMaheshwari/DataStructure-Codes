#include <iostream>
#include <cstring>
#include <cmath>
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

    cout << "Enter the expression and press $ to end." << endl;
    string s[100];int a=0;
    while(2+2 == 4){
        string x;
        cin >> x;
        if(x[0] == '$'){break;}
        s[a] = x;
        a++;
    }

    for(int i=0;i<a;i++){
        if(s[i].size() == 1){
            char c = s[i][0];
            if(c!='+' && c!='-' && c!='*' && c!='/'){

                push(c - '0',S);
            }
            else{
                int x = pop(S);
                int y = pop(S);
                push(sol(x,y,c),S);
            }
        }
        else{
            int j = 0;int x =0;
            while(j<s[i].size()){
                x += (s[i][j]-'0')*pow(10,s[i].size()-1-j);
                j++;
            }
            push(x,S);
        }
    }

    cout << S.element[S.top] << endl;

    return 0;
}
