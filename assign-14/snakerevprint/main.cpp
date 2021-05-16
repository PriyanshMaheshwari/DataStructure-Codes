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

void printrevsnake(queue<BSTPTR> &q,stack<int> &s){
    if(q.size() == 1){return ;}
    static int flag = 0;
    if(flag == 0){
        flag = 1;
        stack<BSTPTR> S;
        while(q.front()!=NULL){
            S.push(q.front());q.pop();
        }
        q.pop();
        while(!S.empty()){
            BSTPTR temp = S.top();
            S.pop();
            s.push(temp->data);
            if(temp->lchild != NULL){q.push(temp->lchild);}
            if(temp->rchild != NULL){q.push(temp->rchild);}
        }
        q.push(NULL);
    }
    else{
        flag = 0;
        stack<BSTPTR> S;
        while(q.front()!=NULL){
            S.push(q.front());q.pop();
        }
        q.pop();
        while(!S.empty()){
            BSTPTR temp = S.top();
            S.pop();
            s.push(temp->data);
            if(temp->rchild != NULL){q.push(temp->rchild);}
            if(temp->lchild != NULL){q.push(temp->lchild);}
        }
        q.push(NULL);
    }
    printrevsnake(q,s);
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
    stack<int> s;
    printrevsnake(q,s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

