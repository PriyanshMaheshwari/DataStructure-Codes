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

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data << T->x<< " ";
    pre(T->lchild);
    pre(T->rchild);
}


void sety(BTPTR &T1,int l){
    BTPTR T = T1;
    if(T == NULL) return;
    T->y  = l;
    sety(T->lchild,l+1);
    sety(T->rchild,l+1);
}

void setx(BTPTR &T){
    static int i = 1;
    if(T==NULL) return;
    setx(T->lchild);
    T->x = i++;
    setx(T->rchild);
}

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    cout << T->data << T->x << " ";
    ino(T->rchild);
}

void printtree(BTPTR T){
    queue<BTPTR> q;
    BTPTR T1 = T;
    q.push(T);
    int a = 0;
    q.push(NULL);
    while(q.size()>1){
        BTPTR temp = q.front();
        q.pop();
        if(temp == NULL) {cout << endl ;a = 0;q.push(NULL);}
        else{
            if(temp->lchild) q.push(temp->lchild);
            if(temp->rchild) q.push(temp->rchild);
            for(int i=0;i<(temp->x-a);i++) cout << " ";
            cout << temp->data;
            a += temp->x-a+1;
        }
    }
}

int main()
{
    BTPTR T = NULL;

     /*cout << "Enter the number of elements." << endl;
    int n;cin >> n;
    char a[n],b[n];
    cout << "Enter the preorder." << endl;
    for(int i=0;i<n;i++) cin >>a[i];
    cout << "Enter the inorder." << endl;
    for(int i=0;i<n;i++) cin >>b[i];*/

    char a[]={'s','m','k','l','t','b','j','e','g','d'};
    char b[]={'k','m','t','l','b','s','j','g','d','e'};

    T = create(a,b,0,9,10);

    setx(T);
    sety(T,1);
    cout << endl;

    printtree(T);

    return 0;
}
