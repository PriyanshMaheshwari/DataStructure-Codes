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

BSTPTR prede(BSTPTR T){
  BSTPTR temp = T->lchild;
  while(temp->rchild) temp=temp->rchild;
  return temp;
}

bool check(int x,vector<int> temp){
  for(int i=0;i<temp.size();i++) if(temp[i] == x) return true;
  return false;
}
int main(){

    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }
    std::vector<int> v;

    while(T){
      if(!T->lchild || check(T->lchild->data,v)){
        v.push_back(T->data);
        T = T->rchild;
      }
      else{
        BSTPTR p = prede(T);
        p->rchild = T;
        T = T->lchild;
      }
    }

    for(int i=0;i<v.size();i++) cout << v[i] << " ";

    cin.get();
    cin.get();
    return 0;
}
