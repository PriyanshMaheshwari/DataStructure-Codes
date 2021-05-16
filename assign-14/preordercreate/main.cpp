#include <iostream>
#include <stack>
using namespace std;

struct btnode{
    struct btnode *lchild;
    int data;
    struct btnode *rchild;
};

typedef struct btnode *BSTPTR;

void createnode(BSTPTR &T,int x){
    BSTPTR temp = new struct btnode;
    temp->data = x;
    temp->lchild = NULL;
    temp->rchild = NULL;
    T = temp;
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

int main()
{
    cout << "Enter the elements of array." << endl;
    int n;cin >> n;
    int a[n];
    for(int i=0;i<n;i++){cin >> a[i];}

    BSTPTR T;
    createnode(T,a[0]);

    stack<BSTPTR> S;
    S.push(T);
    BSTPTR T1 = T;
    int i=1;

    BSTPTR T2 = T;
    while(i<n){
        if(a[i]<T1->data){
                createnode(T1->lchild,a[i]);
                T1 = T1->lchild;
                S.push(T1);
        }
        else{
            while(!S.empty() && a[i]>S.top()->data){ T1 = S.top();S.pop();}
            createnode(T1->rchild,a[i]);
            T1 = T1->rchild;
            S.push(T1);
        }
        i++;
    }

    inorderprint(T);

    return 0;
}
