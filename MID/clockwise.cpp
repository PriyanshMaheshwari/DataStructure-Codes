#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,char a[],int n){
    static int i = 0;
    if(i == n) return T;
    T = nod(a[i]);
    if(T == NULL) return NULL;
    i++;
    T->lchild = create(T->lchild,a,n);
    i++;
    T->rchild = create(T->rchild,a,n);
    return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int main()
{
  cout << "Enter the no.and then the elements.";
    int n;cin >> n;
    char a1[n];
    for(int i=0;i<n;i++) cin >> a1[i];
    BTPTR T = NULL;
    T = create(T,a1,n);

    vector<vector<char > > v;
    vector<char> a;
    queue<BTPTR> q;
    q.push(T);q.push(NULL);

    while(q.size()>1){
      BTPTR temp = new struct btnode;
      temp = q.front();q.pop();
      if(temp == NULL){
        q.push(NULL);
        v.push_back(a);
        cout << endl;
        a.erase(a.begin(),a.end());
      }
      else{
        if(temp->lchild != NULL) q.push(temp->lchild);
        if(temp->rchild != NULL) q.push(temp->rchild);
        a.push_back(temp->data);
        cout << temp->data << " ";
      }
    }

    int cnt=0;int x = v.size()-1;
    for(int i=0;i<v.size();i++){
      if(i%2 == 0){
        for(int j=0;j<v[cnt].size();j++){cout << v[cnt][j] << " ";}
      }
      else{
        for(int j=v[x-cnt].size()-1;j>=0;j--){cout << v[x-cnt][j] << " ";}
        cnt++;
      }
    }

    cin.get();
    cin.get();

    return 0;
}
