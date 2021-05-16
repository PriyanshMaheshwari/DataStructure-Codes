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
        if(temp->lchild){q.push(temp->lchild);}
        if(temp->rchild){q.push(temp->rchild);}
    }
    printlevelorder(q);
}


void preorderprint(BSTPTR T){
    if(T==NULL){return ;}
    cout << T->data << " ";
    preorderprint(T->lchild);
    preorderprint(T->rchild);
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

void postorderprint(BSTPTR T){
    if(T==NULL){return;}
    postorderprint(T->lchild);
    postorderprint(T->rchild);
    cout << T->data << " ";
}

int mi(BSTPTR T){
    while(T->lchild != NULL)
        T= T->lchild;
    return T->data;
}

int ma(BSTPTR T){
    while(T->rchild != NULL){
        T=T->rchild;
    return T->data;
}
}
int main(){

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

    cout << "Preorder : " ;
    preorderprint(T);
    cout << endl;
    cout << "Inorder : " ;
    inorderprint(T);
    cout << endl;
    cout << "Postorder : " ;
    postorderprint(T);
    cout << endl;

    cout << "MINIMUM : " << mi(T) << endl;
    cout << "MAXIMUM : " << ma(T) << endl;

    cin.get();
    cin.get();
    return 0;
}
