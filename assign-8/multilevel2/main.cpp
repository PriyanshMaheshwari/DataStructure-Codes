#include <iostream>
#include <queue>
using namespace std;

struct lnode{
    int data;
    struct lnode *next;
    struct lnode *dlink;
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    T->dlink = NULL;
    L = T;
}

void add(int x,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;
    T1->next = T;
    T->next = NULL;
    T->dlink = NULL;
}

void create(LPTR &L){
        cout << "Enter the entry." << endl;
        int x;cin >> x;
        if(x == -1){return;}
        add(x,L);
        cout << "Do you want to create a branch." << endl;
        int a;cin >> a;
        if(a == 1){create(L->dlink);}
        create(L->next);
}

int main(){

    LPTR L = NULL;
    create(L);
    queue<LPTR> q;
    q.push(NULL);
    LPTR t = L;

    do{
        while(t!=NULL){
            cout << t->data << " ";
            if(t->dlink != NULL){q.push(t->dlink);}
            t = t->next;
        }
        if(q.front() == NULL){
            cout << endl;
            q.pop();
            q.push(NULL);
        }
        t = q.front();
        q.pop();
    }
    while(!q.empty());

    return 0;
}
