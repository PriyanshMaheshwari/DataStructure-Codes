#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct hfnode{
    int f;
    char d;
    struct hfnode* lchild;
    struct hfnode* rchild;
};

typedef struct hfnode *HTPTR;

void perup(HTPTR H[],int n,char a,int k){
    int j = n;
    while(j>0 && H[(j-1)/2]->f > k){
        H[j]->f = H[(j-1)/2]->f;
        H[j]->d = H[(j-1)/2]->d;
        H[(j-1)/2]->f = k;
        H[(j-1)/2]->d = a;
        j = (j-1)/2;
    }
}

void add(HTPTR H[],int n,char a,int k,HTPTR H1,HTPTR H2){
    H[n] = new struct hfnode;
    H[n]->f = k;
    H[n]->d = a;
    H[n]->lchild = H1;
    H[n]->rchild = H2;
    perup(H,n,a,k);
}

void perdown(HTPTR H[],int n,int &i){
    if(i>=n) return;
    int m = i;
    int x = 2*i+1,y = 2*i+2;
    if(x<n && H[x]->f<H[m]->f) m = x;
    if(y<n && H[y]->f<H[m]->f) m = y;
    if(m!=i){
        swap(H[m],H[i]);
        perdown(H,n,m);
    }
}

void preorder(HTPTR T){
    if(T==NULL) return;
    cout << T->d << " ";
    preorder(T->lchild);
    preorder(T->rchild);
}

void del(HTPTR H[],int &n,int k){
    if(n == 0){cout << "Heap is empty." << endl;return;}
    int i = 0;
    swap(H[0],H[n-1]);
    n--;
    perdown(H,n,i);
}

void decode(HTPTR T,string s,int &i){
    if(i>=s.size()) return;
    if(!T->lchild && !T->rchild){
        cout << T->d;i++;
        return;
    }
    if(s[i]=='1') decode(T->rchild,s,++i);
    else decode(T->lchild,s,++i);
}

int main()
{
    HTPTR H[50];
    int n = 0;
    cout << "Enter the char and its freq enter char-$ to exit." << endl;
    while(1){
        int x;char y;
        cin >> y >> x;
        if(y == '$') break;
        add(H,n++,y,x,NULL,NULL);
    }

    HTPTR T = NULL;
    while(n>1){
        HTPTR temp = new struct hfnode;
        int x = H[0]->f;
        temp->d = 'T';
        temp->lchild = H[0];
        del(H,n,H[0]->f);
        temp->f = x+H[0]->f;
        temp->rchild = H[0];
        del(H,n,H[0]->f);
        add(H,n++,temp->d,temp->f,temp->lchild,temp->rchild);
    }
    T = H[0];

    cout << "Enter the string to decode." << endl;
    string s;cin >> s;
    cout << "Decoded : " ;
    int i = 0;
    decode(T,s,i);

    return 0;
}
