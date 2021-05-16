#include <iostream>
#include <cstring>
using namespace std;

int cheog(char a,string OG){
    for(int i=0;i<3;i++){
        if(a==OG[i]){return i;}
    }
    return -1;
}

int cheeg(char a,string EG){
    for(int i=0;i<3;i++){
        if(a==EG[i]){return i;}
    }
    return -1;
}

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

int main(){
    struct stack S;
    S.top = -1;
    S.size = 50;

    cout << "Enter the expression." << endl;

    string s;
    cin >> s;

    string OG="{[(";
    string EG="}])";

    for(int i=0;i<s.size();i++){
        while(cheog(s[i],OG)==-1 && cheeg(s[i],EG)==-1){i++;}

        if(cheog(s[i],OG)!=-1){push(cheog(s[i],OG),S) ;}
        else{
            if(cheeg(s[i],EG) == pop(S)){continue;}
            else{cout << "Wrong";break;}
        }
    }

    if(S.top != -1){cout << "Wrong";}
    else{cout << "Correct" ;}

    return 0;
}
