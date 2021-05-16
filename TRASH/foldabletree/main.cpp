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

bool check(BTPTR T1,BTPTR T2){
    if(T1 == NULL && T2 == NULL) return true;
    else if(T1 == NULL && T2 != NULL) return false;
    else if(T2 == NULL && T1 != NULL) return false;
    bool f1 = check(T1->lchild,T2->rchild);
    bool f2 = check(T1->rchild,T2->lchild);
    if(f1 && f2) return true;
    else return false;
}

int main(){
    cout << "Enter the number of elements." << endl;
	int n;cin >> n;
	int a[n];
	cout << "Enter the elements." << endl;
	for(int i=0;i<n;i++) cin >> a[i];

	BTPTR T = NULL;

	create(T,a,n);

	if(check(T,T)) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}
