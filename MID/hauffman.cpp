#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct hfnode{
    char d;
    struct hfnode* lchild;
    struct hfnode* mchild;
    struct hfnode* rchild;
};

typedef struct hfnode *HTPTR;

HTPTR getnode(char c){
  HTPTR temp = new struct hfnode;
  temp->d = c;
  temp->lchild = temp->mchild = temp->rchild = NULL;
  return temp;
}

HTPTR create(HTPTR T,string s1,string s[],int n,int x,char c[]){
    static int i = 0;
    if(s1.size()>x) return NULL;
    if(i>=n) return NULL;
    int j;
    for(j=0;j<n;j++) if(s1 == s[j]) break;
    if(j==n) T = getnode('#');
    else T = getnode(c[i++]);

    T->lchild = create(T->lchild,s1+"0",s,n,x,c);
    T->mchild = create(T->mchild,s1+"1",s,n,x,c);
    T->rchild = create(T->rchild,s1+"2",s,n,x,c);

    return T;
}


void preorder(HTPTR T){
    if(T==NULL) return;
    cout << T->d << " ";
    preorder(T->lchild);
    preorder(T->rchild);
}

void decode(HTPTR T,char s, vector<int> &a){
    if(T == NULL) {return;}
    if(T->d == s){
        for(int j=0;j<a.size();j++) cout << a[j];
        return;
    }
    if(T->lchild){
        a.push_back(0);
        decode(T->lchild,s,a);
        a.pop_back();
    }
    if(T->mchild){
        a.push_back(1);
        decode(T->mchild,s,a);
        a.pop_back();
    }
    if(T->rchild){
        a.push_back(2);
        decode(T->rchild,s,a);
        a.pop_back();
    }
}

int main()
{
    HTPTR T = NULL;
    cout << "Enter the number of char" << endl;
    int n;cin >> n;
    string s[n];char c[n];
    cout << "Enter the char and its code." << endl;
    for(int i=0;i<n;i++) cin >> c[i] >> s[i];
    string s1 = "";
    cout << "Enter the length of max code." << endl;
    int x;cin >> x;
    T = create(T,s1,s,n,x,c);

    cout << "Enter the string to encode." << endl;
    string s2;cin >> s2;
    cout << "Encoded : " ;
    for(int i=0;i<s2.size();i++){
        vector<int> a;
        decode(T,s2[i],a);
    }


    cin.get();
    cin.get();
    return 0;
}
