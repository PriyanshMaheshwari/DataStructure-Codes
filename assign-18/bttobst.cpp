#include <bits/stdc++.h>
using namespace std;

struct btnode
{
	int data;
	struct btnode* lchild;
	btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int x){
	if(x != 0){
	BTPTR temp = new struct btnode;
	temp->data = x;
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
	if(T == NULL) return;
	cout << T->data << " ";
	pre(T->lchild);
	pre(T->rchild);
}

void crtar(BTPTR T,vector<int>& v){
	if(T==NULL) return;
	v.push_back(T->data);
	crtar(T->lchild,v);
	crtar(T->rchild,v);
}

void convert(BTPTR &T,vector<int>& v){
	static int i=0;
	if(T == NULL) return;
	convert(T->lchild,v);
	T->data = v[i++];
	convert(T->rchild,v);
}

int main(){
	cout << "Enter the number of elements." << endl;
	int n;cin >> n;
	int a[n];
	cout << "Enter the elements." << endl;
	for(int i=0;i<n;i++) cin >> a[i];

	BTPTR T = NULL;

	create(T,a,n);
	pre(T);
	cout << endl;

	vector<int> v;
	crtar(T,v);
	sort(v.begin(),v.end());
	convert(T,v);
	pre(T);
	cout << endl;

	return 0;
}

