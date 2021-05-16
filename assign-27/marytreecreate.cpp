#include <bits/stdc++.h>
using namespace std;

typedef struct mtnode{
  int cnt;
  int key[4];
  mtnode* cptr[5];
}* MPTR;

MPTR getnode(int k,int m){
  MPTR temp = new mtnode;
  temp->cnt = 1;
  temp->key[0] = k;
  for(int i=0;i<m;i++) temp->cptr[i] = NULL;
  return temp;
}

void add(int x,MPTR &T,int m){
  if(T==NULL){
    T = getnode(x,m);
    return;
  }

  if(T->cnt < m-1) {
    T->key[T->cnt] = x;
    T->cnt += 1;
    sort(T->key,T->key+T->cnt);
    return;
  }

  int i = 0;
  while(i<T->cnt){
    if(x<T->key[i]) break;
    i++;
  }
  add(x,T->cptr[i],m);
}

void ino(MPTR T){
  if(!T) return;
  int i = 0;
  while(i<=T->cnt){
    ino(T->cptr[i]);
    if(i == T->cnt) break;
    cout << T->key[i];
    i++;
  }
}

bool sea(MPTR T,int k){
  if(!T) return false;
  int i=0;
  while(i<T->cnt){
    if(k < T->key[i]) break;
    else if(k == T->key[i]) return true;
    else i++;
  }
  return sea(T->cptr[i],k);
}

int main(){
  cout << "Enter the values of data enter -1 to exit." << endl;
  MPTR t = NULL;
  int m = 5;
  while(1){
    int x;cin >> x;
    if(x == -1) break;
    add(x,t,m);
  }

  ino(t);

  cout << endl << "Enter the number you want to search." << endl;
  int k;cin >> k;
  if(sea(t,k)) cout << "Yes" << endl;
  else cout << "No" << endl;

  cin.get();
  cin.get();
  return 0;
}
