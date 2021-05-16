#include <bits/stdc++.h>

using namespace std;

struct btnode{
    int data;
    bool left,mid,right;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int k){
	if(k != 0){
	BTPTR temp = new struct btnode;
	temp->data = k;
	temp->left = temp->right = temp->mid = false;
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

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    cout << T->data <<" ";
    ino(T->rchild);
}

bool check(BTPTR T){
    if(T->left && T->right) return true;
    else if(T->mid && T->left) return true;
    else if(T->right && T->mid) return true;
    return false;
}

void LCA(BTPTR T,int k1,int k2,int &x){
    if(T == NULL || x!=0) return;
    LCA(T->lchild,k1,k2,x);
    LCA(T->rchild,k1,k2,x);
    if(T->data == k1 || T->data == k2) T->mid=true;
    BTPTR temp = T->lchild;
    if(temp!=NULL && (temp->left || temp->mid || temp->right)) T->left = true;
    BTPTR temp2 = T->rchild;
    if(temp2!=NULL && (temp2->left || temp2->mid || temp2->right)) T->right = true;
    if(check(T)) x = T->data;
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
	int k1,k2;
	cout << "Enter the numbers whose LCA you want." << endl;
    cin >> k1 >> k2;

    int l = 0;
    LCA(T,k1,k2,l);
    cout << "LCA is : " << l;

    return 0;
}
