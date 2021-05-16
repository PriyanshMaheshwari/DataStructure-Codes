#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

union u{
    char opd;
    int opn;
};
struct btnode;
typedef struct btnode *BTPTR;
struct btnode{
    BTPTR lchild;
    int flag;
    union u data;
    BTPTR rchild;
};

int sol(int x,int y,char c){
    switch (c){
    case '+' :
        return x+y;
    case '-' :
        return x-y;
    case '*' :
        return x*y;
    case '/' :
        return x/y;
    }
}

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    if(T->flag==0) cout << T->data.opd << " ";
    else cout << T->data.opn << " ";
    ino(T->rchild);
}

int eval(BTPTR T){
    if(T == NULL) return 0;
    else if(T->flag == 1) return T->data.opn;
    else return sol(eval(T->lchild),eval(T->rchild),T->data.opd);
}

int main()
{
    cout << "Enter the expression and press $ to end." << endl;
    string s[100];int a=0;
    while(2+2 == 4){
        string x;
        cin >> x;
        if(x[0] == '$'){break;}
        s[a] = x;
        a++;
    }

    BTPTR T = NULL;
    stack<BTPTR> S;

    for(int i=0;i<a;i++){
        if(s[i].size() == 1){
            char c = s[i][0];
            if(c!='+' && c!='-' && c!='*' && c!='/'){
                int x = c-'0';
                BTPTR temp = new struct btnode;
                temp->data.opn = x;
                temp->flag = 1;
                temp->lchild=temp->rchild = NULL;
                S.push(temp);
            }

            else{
                BTPTR temp = new struct btnode;
                temp->data.opd = c;
                temp->flag = 0;
                temp->rchild = S.top();S.pop();
                temp->lchild = S.top();S.pop();
                S.push(temp);
            }
        }
        else{
            int j = 0;int x =0;
            while(j<s[i].size()){
                x += (s[i][j]-'0')*pow(10,s[i].size()-1-j);
                j++;
            }
            BTPTR temp = new struct btnode;
            temp->data.opn = x;
            temp->flag = 1;
            temp->lchild=temp->rchild = NULL;
            S.push(temp);
        }
    }

    T = S.top();
    ino(T);
    cout << endl << eval(T);

    return 0;
}
