#include <bits/stdc++.h>
using namespace std;

struct btnode
{
	int data;
	int hd;
	struct btnode* lchild;
	btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int x){
	if(x != 0){
	BTPTR temp = new struct btnode;
	temp->data = x;
	temp->hd = -1;
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

void assignhd(BTPTR &T,int l){
	if(T == NULL) return;
	T->hd = l;
	assignhd(T->lchild,l-1);
	assignhd(T->rchild,l+1);
}

void vsum(BTPTR T,std::vector<int>& v){
	static int min = 1;
	static int max = 0;
	if(T == NULL) return;
	if(T->hd < min){v.insert(v.begin(),T->data);min = T->hd;}
	else if(T->hd>max){v.push_back(T->data);max = T->hd;}
	else { v[T->hd-min] += T->data;}
	vsum(T->lchild,v);
	vsum(T->rchild,v);
}

int main(){
	cout << "Enter the number of elements." << endl;
	int n;cin >> n;
	int a[n];
	cout << "Enter the elements." << endl;
	for(int i=0;i<n;i++) cin >> a[i];

	BTPTR T = NULL;

	create(T,a,n);
	assignhd(T,0);
	pre(T);
	cout << endl;

	vector<int> v;
	vsum(T,v);

	for(int i=0;i<v.size();i++) cout << v[i] << " ";

	return 0;
}