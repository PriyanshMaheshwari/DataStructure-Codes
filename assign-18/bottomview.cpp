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

void btprintleft(BTPTR T,vector<int> &v,int &mi){
    if(T == NULL) return;
    if(mi > T->hd){v.insert(v.begin(),T->data);mi = T->hd;}
    else { v[T->hd-mi] = T->data;}
    btprintleft(T->lchild,v,mi);
    btprintleft(T->rchild,v,mi);
}

void btprintright(BTPTR T,vector<int> &v,int ma,int mi){
    if(T == NULL) return;
    if(T->hd>ma){v.push_back(T->data);ma = T->hd;}
    else if(T->hd != 0) { v[T->hd-mi] = T->data;}
    btprintright(T->rchild,v,ma,mi);
    btprintright(T->lchild,v,ma,mi);
}

void btprint(BTPTR T,std::vector<int>& v){
    int mi = 1;
    btprintleft(T,v,mi);
    btprintright(T,v,0,mi);
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
	btprint(T,v);
	for(int i=0;i<v.size();i++) cout << v[i] << " ";

	return 0;
}
