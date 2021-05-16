#include <iostream>
#include <queue>
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

void preorderprint(BSTPTR T){
    if(T==NULL){return ;}
    cout << T->data << " ";
    preorderprint(T->lchild);
    preorderprint(T->rchild);
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

void postorderprint(BSTPTR T){
    if(T==NULL){return;}
    postorderprint(T->lchild);
    postorderprint(T->rchild);
    cout << T->data << " ";
}

void commonnodes(BSTPTR T1,BSTPTR T2){
    stack<BSTPTR> s1,s2;
    while(2+2==4){
        while(T1!=NULL){
            s1.push(T1);
            T1 = T1->lchild;
        }
        while(T2!=NULL){
            s2.push(T2);
            T2 = T2->lchild;
        }
        if(s1.empty() || s2.empty()) break;

        BSTPTR temp1 = s1.top();
        BSTPTR temp2 = s2.top();
        int x = temp1->data ;
        int k = temp2->data;

        if(x<k){
            s1.pop();
            T1 = temp1->rchild;
        }
        else if(x>k){
            s2.pop();
            T2 = temp2->rchild;
        }
        else{
            cout << temp1->data << "," << temp2->data << endl;
            s1.pop();
            s2.pop();
            T1 = temp1->rchild;
            T2 = temp2->rchild;
        }
    }
}

int main()
{
    BSTPTR T1 = NULL;
    BSTPTR T2 = NULL;
    cout << "Enter the entries of first bst and press -1 to stop." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1) break;
        add(T1,x);
    }

    cout << "Enter the entries of second bst and press -1 to stop." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1) break;
        add(T2,x);
    }

    preorderprint(T1);cout << endl;preorderprint(T2);cout << endl;

    commonnodes(T1,T2);

    return 0;
}
