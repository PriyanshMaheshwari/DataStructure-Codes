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

bool check(BTPTR T,int i,int &n){
    if(T == NULL) return true;
    if(i>n) return false;
    bool flag = true;
    if((T->lchild && T->lchild->data < T->data) || (T->rchild && T->rchild->data < T->data)) flag = false;
    if(flag && check(T->lchild,2*i+1,++n) && check(T->rchild,2*i+2,++n)) return true;
    return false;
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
    pre(T);
    cout << endl;
    int n1 = 0;
    if(check(T,0,n1)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

