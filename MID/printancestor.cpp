#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,char a[],int n){
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
  cout << "Enter the no.and then the elements.";
    int n;cin >> n;
    char a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    T = create(T,a,n);
    pre(T);

    cout << "Number whose you ancestors you want." << endl;
    int k;cin >> k;
    stack<BTPTR> S;
    std::vector<char> v;
    S.push(T);
    v.push_back(T->data);
    BTPTR temp = T->lchild;
    int flag = 0;
    while(!S.empty() && flag!=1){
      while(temp!=NULL){
        if(temp->rchild) S.push(temp);
        if(temp->data == k) {flag = 1;break;}
        v.push_back(temp->data);
        temp = temp->lchild;
      }
      if(flag == 1) break;
      temp = S.top();S.pop();
      while(v[v.size()-1] == temp->data) v.pop_back();
      temp = temp->rchild;
    }
    cout << v[v.size()-1] << endl;
    for(int i=0;i<v.size();i++) cout << v[i] << " ";

    cin.get();
    cin.get();
    return 0;
}
