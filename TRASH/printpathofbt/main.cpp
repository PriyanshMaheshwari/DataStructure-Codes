#include <bits/stdc++.h>

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

BTPTR create(BTPTR &T,char a[],int n){
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
void printpath(BTPTR T,char c,int &f){
    static vector<char> v;
    if(T->data == c){
        v.push_back(c);
        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        f = 1;
        return;
    }
    if(f!=1){
        v.push_back(T->data);
        printpath(T->lchild,c,f);
        printpath(T->rchild,c,f);
        v.pop_back();
    }
}

int main()
{
    int n;cin >> n;
    char a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    T = create(T,a,n);
    pre(T);cout << endl;

    cout << "Enter the char whose your path you want." << endl;
    char c;cin >> c;
    int f =0 ;
    printpath(T,c,f);

    return 0;
}
