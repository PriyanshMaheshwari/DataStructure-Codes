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
    if(S.top == -1){cout     }
<< "The stack is empty" << endl;return -1;}
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
    struct stack S1;
    S1.top = -1;
    S1.size = 50;

    struct stack S2;
    S2.top = -1;
    S2.size = 50;

    cout << "Enter the number of elements." << endl;
    int n;
    cin >> n;
    cout << "Enter the value of elements." << endl;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        push(a[i],S1);
    }

    int flag =0;

    for(int i=0;i<n;i++){
        if(i%2 == 0){
            while(S1.top != -1){
                int x = pop(S1);
                if(S2.top == -1){push(x,S2);}
                else{
                    if(peek(S2) > x){
                        int t = pop(S2);
                        push(x,S2);
                        push(t,S2);
                    }
                    else{push(x,S2);}
                }
            }
            a[n-1-i] = pop(S2);
        }
        else{
            while(S2.top != -1){
                int x = pop(S2);
                if(S1.top == -1){push(x,S1);}
                else{
                    if(peek(S1) > x){
                        int t = pop(S1);
                        push(x,S1);
                        push(t,S1);
                    }
                    else{push(x,S1);}
                }
            }
            a[n-1-i] = pop(S1);
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " " ;
    }
    return 0;
}
