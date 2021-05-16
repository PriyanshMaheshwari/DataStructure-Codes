#include <bits/stdc++.h>

using namespace std;

struct btnode{
    char data;
    btnode *ns;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = temp->ns = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,char a[],int l,vector<BTPTR> &v,int n){
    static int i = 0;
    if(i == n) return T;
    T = nod(a[i]);
    if(T == NULL) return NULL;
    i++;
    T->lchild = create(T->lchild,a,l+1,v,n);
    i++;
    T->rchild = create(T->rchild,a,l+1,v,n);
    return T;
}

BTPTR sea(BTPTR T,int k,int i){
  if(i == k) return T;

  BTPTR x = sea(T->lchild,k,i+1);
  if(x) return x;
  else return sea(T->rchild,k,i+1);
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

void assi(BTPTR &T,vector<BTPTR> &v,int k){
  if(!T) return;
  if(k>=v.size()) v.push_back(T);
  else{
    v[k]->ns = T;
    v.erase(v.begin()+k);
    v.insert(v.begin()+k,T);
  }

  assi(T->lchild,v,k+1);
  assi(T->rchild,v,k+1);
}

int main()
{
    int n;cin >> n;
    char a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    vector<BTPTR> v;
    T = create(T,a,0,v,n);
    pre(T);
    cout << endl;
    assi(T,v,0);

    cout << "Ente the level whose values you want." << endl;
    int k;cin >> k;

    BTPTR x = sea(T,k,0);

    while(x){
      cout << x->data << " ";
      x = x->ns;
    }

    cin.get();cin.get();
    return 0;
}
