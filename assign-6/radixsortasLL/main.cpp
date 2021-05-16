#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    L = T;
}

void addafter(int x,int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->data != y){T1 = T1->next ;}
    T->data = x;
    T->next = T1->next;
    T1->next = T;
}

void addbefore(int x,int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){addbegin(x,L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T->data = x;
    T->next = T1->next;
    T1->next = T;
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
}

void printl(LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    while(T!=NULL){
        cout << T->data << " ";
        T = T->next;
    }
}

void deletebegin(LPTR &L){
    L = L->next;
}

void del(int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){deletebegin(L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T = T1->next;
    T1->next = T->next;
    delete(T);
}

int main()
{
    cout << "Enter the number of entries." << endl;
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the entries." << endl;
    for(int i=0;i<n;i++){cin >> a[i];}

    LPTR L[10];
    for(int i=0;i<10;i++){L[i] = NULL;}

    int b=1;
    for(int j=0;j<3;j++){
        int i = 0;
        while(i<n){
            int x = (a[i]/b)%10;
            add(a[i],L[x]);
            i++;
        }
        int k = 0;
        for(int i=0;i<10;i++){
            while(L[i] != NULL){
                // LPTR T = new struct lnode;
                // T = L[i];
                a[k] = L[i]->data;
                deletebegin(L[i]);
                k++;
            }
        }
        b *= 10;
    }

    for(int i=0;i<n;i++){cout << a[i] << " ";}

    cin.get();cin.get();
    return 0;
}
