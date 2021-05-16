#include <iostream>
using namespace std;

struct lnode;
typedef struct lnode *LPTR;

union d{
    char c;
    LPTR dnext;
};

struct lnode{
    int flag;
    union d data;
    LPTR next;
};

void create(string s,LPTR &L){
    static int i = 0;
    if(i==s.size()){L = NULL;return ;}
    else if(s[i]=='{'){
        LPTR T = new struct lnode;
        T->flag = 1;
        L = T;
        i++;
        create(s,T->data.dnext);
        create(s,L->next);
    }
    else if(s[i]=='}'){L=NULL;i++;return;}
    else{
        LPTR T = new struct lnode;
        T->data.c = s[i];
        T->flag = 0;
        L = T;
        i++;
        create(s,L->next);
    }
}

void printl(LPTR &L){
    LPTR T = new struct lnode;
    T = L;
    if(L==NULL){return;}
    else if(T->flag == 0){
        cout << T->data.c;
        printl(L->next);
    }
    else{
        cout << "{" ;
        if(T->data.dnext != NULL){printl(T->data.dnext);}
        cout << "}" ;
        printl(L->next);
    }
}

int main(){
    string s;
    cout << "Enter the expression." << endl;
    cin >> s;
    LPTR L = NULL;

    create(s,L);
    printl(L);

    return 0;
}
