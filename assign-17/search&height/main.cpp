#include <iostream>
#include <string>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,string a,int n){
    static int i = 0;
    if(i == n) return T;
    T = nod(a[i]);
    if(T == NULL) return NULL;
    i++;
    T->lchild = create(T->lchild,a,n);
    i++;
    T->rchild = create(T->rchild,a,n);
    return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

bool sea(char k,BTPTR T){
    if(T == NULL) return false;
    if(T->data == k) return true;
    return (sea(k,T->lchild) || sea(k,T->rchild));
}

int height(BTPTR T){
    if(T==NULL) return -1;
    else
        return 1+max(height(T->lchild),height(T->rchild));
}

int main()
{
    cout << "Enter the string." << endl;
    string s;cin >> s;
    BTPTR T  = NULL;
    create(T,s,s.size());
    pre(T);

    cout << endl << "Enter the data u want to search." << endl;
    char x;cin >> x;
    if(sea(x,T)) cout << "YES" << endl;
    else cout << "NO" << endl;

    cout << "Height of tree : " << height(T);

    return 0;
}
