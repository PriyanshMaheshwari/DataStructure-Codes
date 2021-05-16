#include <bits/stdc++.h>
using namespace std;

int d = 2;

typedef struct btnode{
  int key[4];
  btnode *ptr[5];
  int cnt;
}* BTPTR;

BTPTR getnode(int x){
  BTPTR temp = new btnode;
  for(int i=0;i<=2*d;i++) temp->ptr[i] =NULL;
  temp->cnt = 1;
  temp->key[0] = x;
  return temp;
}

bool compare(pair<BTPTR,int> p1,pair<BTPTR,int> p2){
  return p1.second<p2.second;
}

bool isleaf(BTPTR T){
  for(int i=0;i<=2*d;i++) if(T->ptr[i]) return false;
  return true;
}

void addnum(int x,BTPTR &T){
  T->key[T->cnt++] = x;
  sort(T->key,T->key+T->cnt);
}

void print(queue<BTPTR> &q){
  if(q.size() == 1) return;
  BTPTR temp = q.front();q.pop();
  if(!temp){
    cout << endl;q.push(NULL);
  }
  else{
    cout << "{";
    for(int i=0;i<temp->cnt;i++) {
      cout << temp->key[i] << " ";
      if(temp->ptr[i]) q.push(temp->ptr[i]);
    }
    if(temp->ptr[temp->cnt]) q.push(temp->ptr[temp->cnt]);
    cout << "} ";
  }
  print(q);
}

bool check(BTPTR P){
  for(int i=0;i<=P->cnt;i++){
    if(P->ptr[i]->cnt < 2*d) return true;
  }
  return false;
}

void red(BTPTR &T,int k){
  int x=-1;
  for(int i=k-1;i>=0;i--) if(T->ptr[i]->cnt < 2*d){x=i;break;}
  if(x==-1){
    for(int i=k+1;i<=T->cnt;i++) if(T->ptr[i]->cnt < 2*d){x=i;break;}
  }

  if(x<k){
    while(x!=k){
      T->ptr[x]->key[T->ptr[x]->cnt++] = T->key[x];
      T->key[x] = T->ptr[x+1]->key[0];
      if(!isleaf(T)) T->ptr[x]->ptr[T->ptr[x]->cnt] = T->ptr[x+1]->ptr[0];
      for(int i=0;i<T->ptr[x+1]->cnt-1;i++){
        T->ptr[x+1]->key[i] = T->ptr[x+1]->key[i+1];
        if(!isleaf(T)) T->ptr[x+1]->ptr[i] = T->ptr[x+1]->ptr[i+1];
      }
      if(!isleaf(T)) T->ptr[x]->ptr[T->ptr[x]->cnt-1] = T->ptr[x]->ptr[T->ptr[x]->cnt];
      T->ptr[x+1]->cnt--;
      x++;
    }
  }
  else{
    while(x!=k){
      addnum(T->key[x-1],T->ptr[x]);
      if(!isleaf(T)){
        for(int i=T->ptr[x]->cnt-1;i>0;i--){
          T->ptr[x]->ptr[i+1] = T->ptr[x]->ptr[i];
        }
      }
      T->key[x-1] = T->ptr[x-1]->key[T->ptr[x-1]->cnt-1];
      if(!isleaf(T)) T->ptr[x]->ptr[0] = T->ptr[x-1]->ptr[T->ptr[x-1]->cnt];
      T->ptr[x-1]->cnt--;
      x--;
    }
  }
}

void overflow(BTPTR &T,stack<BTPTR> &S,int a[]){
  if(S.size() == 0){
    BTPTR N = getnode(a[d+1]);
    for(int i=d+2;i<2*d+1;i++) addnum(a[i],N);
    T->cnt = d;
    for(int i=0;i<d;i++) T->key[i] = a[i];
    addnum(a[d],N);
    N->ptr[2*d] = T->ptr[2*d];
    T->ptr[2*d] = N;
    BTPTR P = getnode(a[d]);
    P->ptr[0] = T;P->ptr[1] = N;
    S.push(P);
    return;
  }

  else{
    BTPTR P = S.top();S.pop();
    if(P->cnt < 2*d){
      BTPTR N = getnode(a[d+1]);
      for(int i=d+2;i<2*d+1;i++) addnum(a[i],N);
      T->cnt = d;
      for(int i=0;i<d;i++) T->key[i] = a[i];
      addnum(a[d],N);
      N->ptr[2*d] = T->ptr[2*d];
      T->ptr[2*d] = N;
      vector<pair<BTPTR,int>> v;
      for(int i=0;i<=P->cnt;i++) v.push_back(make_pair(P->ptr[i],P->ptr[i]->key[0]));
      v.push_back(make_pair(N,N->key[0]));
      addnum(a[d],P);
      sort(v.begin(),v.end(),compare);
      for(int i=0;i<=P->cnt;i++) P->ptr[i] = v[i].first;
      S.push(P);return;
    }

    else{
      //if(!check(P)){
        BTPTR N = getnode(a[d+1]);
        for(int i=d+2;i<2*d+1;i++) addnum(a[i],N);
        T->cnt = d;
        for(int i=0;i<d;i++) T->key[i] = a[i];
        addnum(a[d],N);
        N->ptr[2*d] = T->ptr[2*d];
        T->ptr[2*d] = N;
        int b[2*d+1];
        for(int i=0;i<2*d;i++) b[i] = P->key[i];
        b[2*d] = a[d];
        sort(b,b+2*d+1);
        vector<pair<BTPTR,int>> v;
        for(int i=0;i<=P->cnt;i++) v.push_back(make_pair(P->ptr[i],P->ptr[i]->key[0]));
        v.push_back(make_pair(N,N->key[0]));
        sort(v.begin(),v.end(),compare);
        overflow(P,S,b);
        BTPTR X = S.top();
        int k;
        for(k=0;k < X->cnt;k++){if(P->key[0] == X->ptr[k]->key[0]) break;}
        for(int i=0;i<v.size();i++){
          if(i<v.size()/2){P->ptr[i] = v[i].first;}
          else{X->ptr[k+1]->ptr[i-v.size()/2] = v[i].first;}
        }
        S.push(P);return;
      //}
      // else{
      //   int k;
      //   for(k=0;k<P->cnt;k++){if(a[0] == P->ptr[k]->key[0]) break;}
      //   red(P,k);
      //   S.push(P);
      //   overflow(T,S,a);
      //   return;
      // }
    }
  }
}

void add(int x,BTPTR &T,stack<BTPTR> &S){
  if(!T){
    T = getnode(x);S.push(T);return;
  }
  else if(isleaf(T)){
    if(T->cnt < 2*d) {S.push(T);addnum(x,T);return;}
    else{
      //if(S.size()==0 || !check(S.top())){
        int a[2*d+1];
        for(int i=0;i<2*d;i++) a[i] = T->key[i];
        a[2*d] = x;
        sort(a,a+2*d+1);
        overflow(T,S,a);
        S.push(T);return;
      // }
      // else{
      //   BTPTR P = S.top();
      //   int k;
      //   for(k=0;k<P->cnt;k++){if(T->key[0] == P->ptr[k]->key[0]) break;}
      //   red(P,k);
      //   addnum(x,T);
      //   S.push(T);
      //   return;
      // }
    }
  }
  else{
    int i;
    S.push(T);
    for(i=0;i<T->cnt;i++) if(T->key[i] > x){
      break;
    }
    add(x,T->ptr[i],S);
  }
}

int main(){
  cout << "Enter the values." << endl;
  BTPTR T = NULL;
  int x = 1;
  while(1){
    //int x;cin >> x;
    if(x == 16) break;
    stack<BTPTR> S;
    add(x,T,S);
    while(S.size()!=1) S.pop();
    T = S.top();
    queue<BTPTR> q;
    q.push(T);q.push(NULL);
    print(q);
    cout << endl;
    x++;
    BTPTR temp = T;
    while(temp->ptr[0]) temp = temp->ptr[0];
    while(temp){
      for(int i=0;i<temp->cnt;i++){cout << temp->key[i] << " ";}
      temp = temp->ptr[2*d];
    }
    cout << endl;
  }

  cin.get();cin.get();
  return 0;
}
