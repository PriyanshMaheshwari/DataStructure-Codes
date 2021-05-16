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
    cout << T->key[i] <<" ";
    i++;
  }
}

bool isleaf(MPTR T){
  for(int i=0;i<=T->cnt;i++){
    if(T->cptr[i]) return false;
  }
  return true;
}

void remove(MPTR &T,int k){
  int i=0;
  while(T->key[i] != k) i++;
  while(i<T->cnt-1) {T->key[i] = T->key[i+1];i++;}
  T->cnt -= 1;
}

void del(MPTR &T,int k){
  if(!T) return;
  int i=0,flag = 0;
  while(i<T->cnt){
    if(k < T->key[i]) break;
    else if(k == T->key[i]){flag = 1;break;}
    else i++;
  }
  if(flag==0)del(T->cptr[i],k);
  else{
    if(isleaf(T)){
      remove(T,k);
      return;
    }
    else{
      int j = 0;
      while(T->key[j] != k) j++;
      if(T->cptr[j]){
        MPTR temp = T->cptr[j];
        swap(T->key[j],temp->key[temp->cnt-1]);
        del(temp,k);
      }
      else if(T->cptr[j+1]){
        MPTR temp = T->cptr[j+1];
        swap(T->key[j],temp->key[0]);
        del(temp,k);
      }
      else{
        int l = j;
        for(l;l<T->cnt-1;l++){
          T->key[l] = T->key[l+1];
          T->cptr[l+1] = T->cptr[l+2];
        }
        T->cnt -= 1;
      }
    }
    return;
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

  ino(t);

  cout << endl << "Enter the number you want to delete." << endl;
  int k;cin >> k;
  del(t,k);

  ino(t);

  cin.get();
  cin.get();
  return 0;
}
