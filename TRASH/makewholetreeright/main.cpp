#include <bits/stdc++.h>
using namespace std;

struct btnode{
    int data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int k){
	if(k != 0){
	BTPTR temp = new struct btnode;
	temp->data = k;
	temp->lchild = temp->rchild = NULL;
	return temp;}
	else return NULL;
}

BTPTR create(BTPTR &T,int a[],int n){
	static int i = 0;
	if(i>=n) return NULL;
	T = newnode(a[i++]);
	if(T==NULL) return NULL;
	T->lchild = create(T->lchild,a,n);
	T->rchild = create(T->rchild,a,n);
	return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
    pre(T->lchild);
    pre(T->rchild);
}

BTPTR modify(BTPTR &T){
    BTPTR rch = T->rchild;
    BTPTR temp = T;

    if(T->lchild){
        temp = modify(T->lchild);

        T->rchild = T->lchild;
        T->lchild = NULL;
    }

    if(!rch) return temp;

    temp->rchild = rch;
    temp = modify(rch);
    return temp;
}

int main()
{
    cout << "Enter the number of elements." << endl;
	int n;cin >> n;
	int a[n];
	cout << "Enter the elements." << endl;
	for(int i=0;i<n;i++) cin >> a[i];

	BTPTR T = NULL;

	create(T,a,n);
	T = modify(T);

	while(T->rchild){cout << T->data  << " "; T= T->rchild;}
    return 0;
}
