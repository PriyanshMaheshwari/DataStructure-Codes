#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct lnode{
    int data;
    int cnt;
    struct lnode* next[5];
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->cnt = 0;
    for(int i=0;i<5;i++){T->next[i] == NULL;}
    T->next[T->cnt] = L;
    L = T;
}

void add(int x,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next[0] != NULL){T1 = T1->next[0];}
    T->data = x;
    T->cnt = 0;
    T1->next[T1->cnt] = T;
    for(int i=0;i<5;i++){T->next[i] == NULL;}
}

void create(LPTR &L){
        cout << "Enter the entry." << endl;
        int x;cin >> x;
        if(x == -1){return;}
        add(x,L);
        while(1){
            cout << "Do you want to create a branch." << endl;
            int a;cin >> a;
            if(a == 1){ L->cnt++;create(L->next[L->cnt]);}
            if(a == 0){break;}
        }
        create(L->next[0]);
}

void pri(LPTR L,vector<int> &v){
  if(!L){
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;return;
  }

  v.push_back(L->data);
  for(int i=0;i<=L->cnt;i++) pri(L->next[i],v);
  v.pop_back();
}

int main()
{
    LPTR L = NULL;
    create(L);
    vector<int> v;
    pri(L,v);

    cin.get();cin.get();
    return 0;
}
