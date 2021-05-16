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

void printlevel(queue<MPTR> &q){
  if(q.size() == 1) return;
  MPTR t = q.front();q.pop();
  if(t == NULL){
    cout << endl;
    q.push(NULL);
    printlevel(q);
  }

  else{
    int i=0;
    while(i<t->cnt){
      if(t->cptr[i]) q.push(t->cptr[i]);
      cout << t->key[i] << " ";
      i++;
    }
    if(t->cptr[i]) q.push(t->cptr[i]);
  }
  printlevel(q);
}

void ino(MPTR T){
  if(!T) return;
  int i = 0;
  while(i<=T->cnt){
    ino(T->cptr[i]);
    if(i == T->cnt) break;
    cout << T->key[i] << " ";
    i++;
  }
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

  //ino(t);cout << endl;

  queue<MPTR> q;
  q.push(t);q.push(NULL);
  printlevel(q);

  cin.get();
  cin.get();
  return 0;
}
