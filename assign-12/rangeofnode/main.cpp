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

void printlevelorder(queue<BSTPTR> &q){
    if(q.size() == 1){return ;}
    BSTPTR temp = new struct btnode;
    temp = q.front();
    q.pop();
    if(temp == NULL){cout << endl;q.push(temp);}
    else{
        cout << temp->data << " ";
        if(temp->lchild != NULL){q.push(temp->lchild);}
        if(temp->rchild != NULL){q.push(temp->rchild);}
    }
    printlevelorder(q);
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

    queue<BSTPTR> q;
    q.push(T);
    q.push(NULL);
    printlevelorder(q);

    cout << endl;

    cout << "Enter the data of node whose range you want to find." << endl;
    int k;cin >> k;
    range(k,T);

    return 0;
}
