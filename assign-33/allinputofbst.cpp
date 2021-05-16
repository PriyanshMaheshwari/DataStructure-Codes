#include <iostream>
#include <queue>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};

typedef struct btnode* BSTPTR;

void add(BSTPTR &T,int k){
    if(T == NULL){
        BSTPTR temp = new struct btnode;
        temp->data = k;
        temp->lchild = NULL;
        temp->rchild = NULL;
        T = temp;
    }
    else if(T->data > k){add(T->lchild,k);}
    else add(T->rchild,k);
}

void preorderprint(BSTPTR T){
    if(T==NULL){return ;}
    cout << T->data << " ";
    preorderprint(T->lchild);
    preorderprint(T->rchild);
}

void pri(int n,vector<BSTPTR> &p,vector<int> &a,int &cnt){
  if(a.size() == n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cnt++;
    cout << endl;
    return;
  }

  for(int i=0;i<p.size();i++){
    BSTPTR t = p[i];
    p.erase(p.begin()+i);
    if(t->lchild) p.push_back(t->lchild);
    if(t->rchild) p.push_back(t->rchild);
    a.push_back(t->data);
    pri(n,p,a,cnt);
    a.pop_back();
    if(t->lchild) p.pop_back();
    if(t->rchild) p.pop_back();
    p.insert(p.begin()+i,t);
  }
}

int main(){

    BSTPTR T = NULL;
    int n = 0;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);n++;
    }
    cout << endl;
    vector<int> a;
    vector<BSTPTR> p;
    p.push_back(T);
    int cnt = 0;
    pri(n,p,a,cnt);
    cout << endl << "Total number of ways : " << cnt << endl;

    cin.get();
    cin.get();
    return 0;
}
