#include <iostream>
#include <stack>
using namespace std;

struct btnode{
    struct btnode* lchild;
    char data;
    struct btnode* rchild;
};

typedef struct btnode* BTPTR;

BTPTR createnode(char c){
    BTPTR temp = new btnode;
    temp->data = c;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int main(){

    BTPTR T1 = NULL;
    stack<BTPTR> S;

    int f = 1;
    while(1){
        cout << "Give the entry" << endl;
        char x;cin >> x;
        int y = 0;
        T1 = createnode(x);
        S.push(T1);
        cout << "Does it have a lchild." << endl;
        int a;cin >> a;
        if(a == 1)    T1 = T1->lchild;
        else{
            while(!S.empty()){
                T1=S.top();S.pop();
                cout << "Does it have a rchild." << endl;
                cin >> y;
                if(y == 1){T1 = T1->rchild;break;}
            }
        }
        if(S.empty() && y!=1) break;
    }

    pre(T1);

    return 0;

}
