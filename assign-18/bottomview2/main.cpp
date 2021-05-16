#include <bits/stdc++.h>

using namespace std;

struct btnode{
    char data;
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

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data <<  " ";
    pre(T->lchild);
    pre(T->rchild);
}

void sety(BTPTR &T1,int l){
    BTPTR T = T1;
    if(T == NULL) return;
    T->y  = l;
    sety(T->lchild,l+1);
    sety(T->rchild,l+1);
}

void assignhd(BTPTR &T,int l){
	if(T == NULL) return;
	T->hd = l;
	assignhd(T->lchild,l-1);
	assignhd(T->rchild,l+1);
}

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    cout << T->data <<" ";
    ino(T->rchild);
}

void botval(BTPTR T,vector<vector <int> > &v){
    static int min = 1;
	static int max = 0;
	if(T == NULL) return;
	if(T->hd < min){
            vector<int> b;
            b.push_back(T->data);
            b.push_back(T->y);
            v.insert(v.begin(),b);
            min = T->hd;
    }
	else if(T->hd>max){
            vector<int> b;
            b.push_back(T->data);
            b.push_back(T->y);
            v.push_back(b);
            max = T->hd;
    }
	else {
            vector<int> b;
            b = v[T->hd-min];
            if(b[1] <= T->y){b[0] = T->data;b[1] = T->y;}
            v[T->hd-min] = b;
    }
	botval(T->lchild,v);
	botval(T->rchild,v);
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
	assignhd(T,0);sety(T,0);

	vector<vector <int> > v;
	botval(T,v);

	for(int i=0;i<v.size();i++) cout << v[i][0] << " ";

    return 0;
}
