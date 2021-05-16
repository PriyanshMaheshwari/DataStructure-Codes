#include <bits/stdc++.h>
using namespace std;

struct node{
    char c;
    int f;
    node* left;
    node* right;
    node(char x,int y) : c(x),f(y),left(NULL),right(NULL) {};
    node(char x,int y,node* k1,node* k2) : c(x),f(y),left(k1),right(k2) {};
};

typedef node* PTR;

struct cmp{
    bool operator()(PTR &p1,PTR &p2){
      return p1->f > p2->f;
    }
};

void func(PTR T,map<char,string> &m,string s){
  if(!T) return;
  if(T->c != '#'){
    m[T->c] = s;
  }
  else{
    func(T->left,m,s+'0');
    func(T->right,m,s+'1');
  }
}

void pre(PTR T,map<char,string> m){
  if(!T) return;
  if(T->c != '#') cout << m[T->c] << " ";
  pre(T->left,m);
  pre(T->right,m);
}

int main() {
  int T;cin >> T;
  while(T--){
    string s;cin >> s;
    vector<int> v(s.size());
    for(int i=0;i<v.size();i++) cin >> v[i];

    priority_queue<PTR,vector<PTR>,cmp> p;
    for(int i=0;i<v.size();i++){
      PTR T = new node(s[i],v[i]);
      p.push(T);
    }

    while(p.size()>1){
      PTR k1 = p.top();p.pop();
      PTR k2 = p.top();p.pop();
      PTR temp = new node('#',k1->f+k2->f,k1,k2);
      p.push(temp);
    }

    PTR t = p.top();
    map<char,string> m;
    func(t,m,"");
    //cout << m['a'] << endl;
    pre(t,m);
  }
	return 0;
}
