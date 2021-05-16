#include <iostream>
#include <stack>
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

int checkdeadend(BSTPTR T,int mi,int ma){
    static int i=0;
    if(T==NULL){return 0;}
    if(mi==ma){i++;cout << T->data << " ";}
    else if(T->rchild!=NULL && T->lchild==NULL && T->data==mi){i++;cout << T->data << " ";}
    else if(T->lchild!=NULL && T->rchild==NULL && T->data==ma){i++;cout << T->data << " ";}
    int x = checkdeadend(T->lchild,mi,T->data-1);
    int y = checkdeadend(T->rchild,T->data+1,ma);
    return i;
}

int main()
{
    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }

    int x = checkdeadend(T,0,1000);
    cout << endl << x << endl;

    return 0;
}
