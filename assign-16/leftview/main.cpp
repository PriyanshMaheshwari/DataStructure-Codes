#include <bits/stdc++.h>

using namespace std;

struct btnode{
    char data;
    int x,y;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR create(char a[],char b[],int i,int n,int n1){
    BTPTR temp = new btnode;
    static int k = 0;
    if(k>=n1) return NULL;
    if(i>n) return NULL;

    temp->data = a[k++];
    temp->lchild = temp->rchild = NULL;
    if(i==n) return temp;

    int x;
    for(x = i;x<=n;x++){
        if(b[x] == temp->data) break;
    }

    temp->lchild = create(a,b,i,x-1,n1);
    temp->rchild = create(a,b,x+1,n,n1);
    return temp;
}

void printlview(BTPTR T,int l){
    static int m = 0;
    if(T == NULL) return;
    if(m<l){cout << T->data<< " ";m++;}
    printlview(T->lchild,l+1);
    printlview(T->rchild,l+1);
}

int main()
{
    BTPTR T = NULL;
    char a[]={'s','m','k','l','t','b','j','e','g','d'};
    char b[]={'k','m','t','l','b','s','j','g','d','e'};

    T = create(a,b,0,9,10);

    printlview(T,1);

    return 0;
}
