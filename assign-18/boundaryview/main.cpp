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

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
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

void minhd(BTPTR T,int &h){
    if(T == NULL) return;
    if(T->hd < h){h = T->hd;}
    minhd(T->lchild,h);
    minhd(T->rchild,h);
}

void bounval(BTPTR T,vector<vector <int> > &v){
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
            if(b.size() == 2){
                if(T->y < b[1]){
                    b.insert(b.begin(),T->y);
                    b.insert(b.begin(),T->data);
                }
                else{
                    b.push_back(T->data);
                    b.push_back(T->y);
                }
            }
            else{
                if(T->y < b[1]){
                    b[1] = T->y;
                    b[0] = T->data;
                }
                else if(T->y >= b[3]){
                    b[3] = T->y;
                    b[2] = T->data;
                }
            }
            v[T->hd-min] = b;
    }
	bounval(T->lchild,v);
	bounval(T->rchild,v);
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
	bounval(T,v);
	int h = 0;
	minhd(T,h);
	if(h!=0) h=-h;

	cout << "Anti-Clockwise : " ;

	int i;
	for(i=h;i>=0;i--) cout << v[i][0] << " ";
    i++;
    for(;i<=h;i++) if(v[i].size()>2) cout << v[i][2] << " ";
    for(;i<v.size();i++){
        if(v[i].size()>2) cout << v[i][2] << " ";
        else cout << v[i][0] << " ";
    }
    i--;
    for(;i>h;i--) if(v[i].size()>2) cout << v[i][0] << " ";

    cout << endl;
    cout << "Clockwise : ";
    i = h;
    for(;i<v.size();i++) cout << v[i][0] << " ";
    i--;
    for(;i>=h;i--) if(v[i].size()>2) cout << v[i][2] << " ";
    for(;i>=0;i--){
        if(v[i].size()>2) cout << v[i][2] << " ";
        else cout << v[i][0] << " ";
    }
    i++;
    for(;i<h;i++) if(v[i].size()>2) cout << v[i][0] << " ";


    return 0;
}
