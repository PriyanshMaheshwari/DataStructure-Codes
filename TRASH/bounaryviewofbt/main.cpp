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

void leftview(BTPTR T){
    if(T == NULL) return;
    if(T->lchild){
        cout << T->data << " ";
        leftview(T->lchild);
    }
    else if(T->rchild){
        cout << T->data << " ";
        leftview(T->rchild);
    }
}

void rightview(BTPTR T){
    if(T == NULL) return;
    if(T->rchild){
        cout << T->data << " ";
        rightview(T->rchild);
    }
    else if(T->lchild){
        cout << T->data << " ";
        rightview(T->lchild);
    }
}

void leaf(BTPTR T){
    if(T == NULL) return;
    if(!T->lchild && !T->rchild) cout << T->data << " ";
    leaf(T->lchild);
    leaf(T->rchild);
}

void bound(BTPTR T){
    cout << T->data << " ";
    leftview(T->lchild);
    leaf(T->lchild);
    leaf(T->rchild);
    rightview(T->rchild);
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
	bound(T);
    return 0;
}
