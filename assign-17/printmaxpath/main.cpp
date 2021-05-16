#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct btnode{
    int data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(int a){
    if(a != -1){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,int a[],int n){
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

void printmaxpath(BTPTR T,vector<int> &main,vector<int> &temp,int s){
    static int m = 0;

    if(T == NULL){
        if(s>m){
            m = s;
            main = temp;
        }
        return;
    }

    temp.push_back(T->data);
    printmaxpath(T->lchild,main,temp,s+T->data);
    printmaxpath(T->rchild,main,temp,s+T->data);
    temp.pop_back();
}

int main()
{
    cout << "Enter the number of elements" << endl;
    int n;cin >> n;
    int a[n];
    cout << "Enter the elements." << endl;
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    create(T,a,n);
    vector<int> main,temp;

    printmaxpath(T,main,temp,0);
    for(int i=0;i<main.size();i++) cout << main[i] << " ";

    return 0;
}
