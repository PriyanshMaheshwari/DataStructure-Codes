#include <iostream>
#include <stack>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};

typedef struct btnode* BSTPTR;

void add(BSTPTR &T,int k){
    if(T == NULL){
        BSTPTR temp = new struct btnode;
        temp->data = k;
        temp->lchild = NULL;
        temp->rchild = NULL;
        T = temp;
    }
    else if(T->data > k){add(T->lchild,k);}
    else add(T->rchild,k);
}

int main()
{
    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }

    stack<BSTPTR> S;
    S.push(T);
    while(!S.empty()){
        BSTPTR temp = S.top();
        S.pop();
        while(temp != NULL){
            if(temp->rchild != NULL){S.push(temp->rchild) ;}
            cout << temp->data << " ";
            temp = temp->lchild;
        }
    }

    return 0;
}
