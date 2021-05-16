#include <bits/stdc++.h>

using namespace std;

struct btnode{
    int data;
    int hd,y;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int k){
	if(k != 0){
	BTPTR temp = new struct btnode;
	temp->data = k;
	temp->hd = -1;temp->y = -1;
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

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    cout << T->data <<" ";
    ino(T->rchild);
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
    pre(T->lchild);
    pre(T->rchild);
}

void inoarr(BTPTR T,vector<int> &a){
    if(T==NULL) return;
    inoarr(T->lchild,a);
    a.push_back(T->data);
    inoarr(T->rchild,a);
}

void sw(int &a,int &b){
    int z = a;
    a = b;
    b = z;
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
	vector<int> v;
	inoarr(T,v);

	int cnt = 0;
	for(int i=0;i<v.size()-1;i++){
        int x = i,flag = 0;
        while(x<v.size()){
            if(v[x]<v[i]) {flag = 1;break; }
            x++;
        }
        if(flag == 1){
            cnt++;
            sw(v[x],v[i]);
        }
        cout << endl;
	}

	cout << "No. of swaps : " << cnt << endl;

    return 0;
}
