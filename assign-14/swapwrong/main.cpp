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

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

void swa(BSTPTR T,int a,int b){
    BSTPTR temp = T;
    while(temp->data != a){
        if(temp->data > a) temp=temp->lchild;
        else temp = temp->rchild;
    }
    temp->data = b;
    BSTPTR temp2 = T;
    while(temp2->data != b){
        if(temp2->data > b) temp2=temp->lchild;
        else temp2 = temp2->rchild;
    }
    temp2->data = a;
}

void checkdeadend(BSTPTR T,int mi,int ma,BSTPTR &T1,BSTPTR &T2){
    if(T==NULL){return ;}
    if(T->data<mi || T->data>ma){
            if(T1==NULL){T1 = T;}
            else if(T2==NULL){T2 = T;}
    }
    checkdeadend(T->lchild,mi,T->data-1,T1,T2);
    checkdeadend(T->rchild,T->data+1,ma,T1,T2);
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
    cout << "Enter the values you want to swap." << endl;
    int a,b;
    cin >> a >> b;

    swa(T,a,b);
    inorderprint(T);
    cout << endl;

    BSTPTR T1=NULL;
    BSTPTR T2=NULL;
    checkdeadend(T,0,1000,T1,T2);

    int z = T1->data;
    T1->data = T2->data;
    T2->data = z;

    inorderprint(T);

    return 0;
}
