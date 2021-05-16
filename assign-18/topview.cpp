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

void printlefttop(BTPTR T){
    static int mi = 1;
    if(T == NULL) return;
    if(mi > T->hd){cout << T->data << " ";mi = T->hd;}
    printlefttop(T->lchild);
    printlefttop(T->rchild);
}

void printrighttop(BTPTR T){
    static int ma = 1;
    if(T == NULL) return;
    if(ma < T->hd){cout << T->data << " ";ma = T->hd;}
    printrighttop(T->rchild);
    printrighttop(T->lchild);
}

void printtop(BTPTR T){
	printlefttop(T);
	cout << endl;
	printrighttop(T);
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
	printtop(T);


	return 0;
}

/*1
2
3
0
0
4
0
0
5
6
0
0
7
0
0*/

/*1
2
4
0
0
5
0
8
20
21
22
0
0
0
0
3
0
0*/

