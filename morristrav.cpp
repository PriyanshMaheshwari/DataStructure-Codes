#include <bits/stdc++.h>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

void trav(BTPTR T){
  if(!T) return;
  BTPTR pre = NULL;
  BTPTR cur = T;

  while(cur){
    if(!cur->lchild){
      cout << cur->data << " ";
      cur = cur->rchild;
    }
    else{
      pre = cur->lchild;
      while(pre->rchild && pre->rchild != cur) pre=pre->rchild;
      if(!pre->rchild){
        pre->rchild = cur;
        cur = cur->lchild;
      }
      else{
        pre->rchild = NULL;
        cout << cur->data << " ";
        cur = cur->rchild;
      }
    }
  }
}

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,std::vector<char> a,int n){
    static int i = 0;
    if(i == n) return T;
    T = nod(a[i]);
    if(T == NULL) return NULL;
    i++;
    T->lchild = create(T->lchild,a,n);
    i++;
    T->rchild = create(T->rchild,a,n);
    return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int main()
{
    vector<char> a;
    char c;cin >> c;
    while(c!='$') {a.push_back(c);cin >> c;}
    int n = a.size();
    BTPTR T = NULL;
    T = create(T,a,n);
    pre(T);
    cout << endl;
    trav(T);

    cin.get();cin.get();
    return 0;
}
//ABC++D++eF++G++$
