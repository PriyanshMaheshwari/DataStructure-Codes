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

    queue<BTPTR> q;
    q.push(T);q.push(NULL);
    
    while(q.size() > 1){
      BTPTR temp = q.front();q.pop();
      if(!temp){
        q.push(NULL);
      }
      else{
        temp->ns = q.front();
        if(temp->lchild) q.push(temp->lchild);
        if(temp->rchild) q.push(temp->rchild);
      }
    }

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
