#include <bits/stdc++.h>
using namespace std;

typedef struct bdnode{
  int cnt;
  int key[4];
  bdnode* ptr[5];
}* ptr;

ptr getnode(int k){
  ptr temp = new struct bdnode;
  temp->cnt = 1;
  temp->key[0] = k;
  for(int i=0;i<5;i++) temp->ptr[i] = NULL;
}

bool isleaf(ptr T){
  for(int i=0;i<=T->cnt;i++){
    if(T->ptr[T->cnt]) return false;
  }
  return true;
}

void addnum(int x,ptr& T){
  T->key[T->cnt] = x;
  T->cnt += 1;
  sort(T->key,T->key+T->cnt);
}

bool sea(int x,ptr T){
  for(int i=0;i<T->cnt;i++){
    if(x == T->key[i]) return true;
  }
  return false;
}

void ino(ptr T){
  if(!T) return;
  int i = 0;
  while(i<=T->cnt){
    ino(T->ptr[i]);
    if(i == T->cnt) break;
    cout << T->key[i];
    i++;
  }
}


int isemp(ptr T,ptr P){
  int i=0;
  for(i;i<=P->cnt;i++) if(P->ptr[i] == T) break;
  int j = i-1;
  while(j>=0){
    if(P->ptr[j]->cnt < 4) return j;
    j--;
  }

  j = i+1;
  while(j<=P->cnt){
    if(P->ptr[i+1]->cnt < 4) return j;
    j++;
  }

  return -1;
}

void overflow(ptr&head,ptr &T,int a[],stack<ptr> &S,int x){
  if(S.size() == 0){
    ptr N = getnode(a[3]);addnum(a[4],N);
    T->cnt = 2;
    T->key[0] = a[0];T->key[1] = a[1];
    ptr P = getnode(a[2]);
    P->ptr[0] = T;P->ptr[1] = N;
    S.push(P);
    return;
  }

  else{
    ptr P = S.top();S.pop();
    if(P->cnt != 4){
      cout << P->cnt;
      ptr N = getnode(a[3]);addnum(a[4],N);
      T->cnt = 2;
      T->key[0] = a[0];T->key[1] = a[1];
      addnum(a[2],P);
      int k=0;
      ptr tem = P->ptr[0];
      while(k<P->cnt) {if(P->key[k] == a[2]) break;k++;}
      for(int l = P->cnt;l>k;l--){
        if(l==k+1) P->ptr[l] = N;
        else P->ptr[l] = P->ptr[l-1];
      }
      S.push(P);
      return;
    }

    else{
      //cout << "hi";
      int z = isemp(T,P);
      if(z == -1){
        ptr N = getnode(a[3]);addnum(a[4],N);
        T->cnt = 2;
        T->key[0] = a[0];T->key[1] = a[1];
        int b[5];int flag = 0;
        int j = 0;
        for(int i=0;i<5;i++){
          if(j<4 && (P->key[j] < a[2] || flag == 1)) b[i] = P->key[j++];
          else {b[i] = a[2];flag = 1;}
        }
        ptr p[5];
        for(int k=0;k<5;k++) p[k] = P->ptr[k];

        overflow(head,P,b,S,x);
        ptr x1 = S.top();S.pop();
        ptr temp1 = x1->ptr[0],temp2 = x1->ptr[1];
        int k = 0;
        while(x1->key[k] != b[2]) k++;
        ptr p1 = x1->ptr[k],p2 = x1->ptr[k+1];

        S.push(x1);
        if(sea(a[2],p1)){
          int m=0,n=0;
          while(p1->key[m] != a[2]) {p1->ptr[m++] = p[n++];}
          p1->ptr[m++] = p[n++];p1->ptr[m++] = N;
          while(m<=p1->cnt)  p1->ptr[m++] = p[n++];
          m = 0;
          while(m<=p2->cnt) p2->ptr[m++] = p[n++];
          S.push(p1);
        }
        else if(sea(a[2],p2)){
          int m=0,n=0;
          while(m<=p1->cnt) p1->ptr[m++] = p[n++];
          m=0;
          while(p2->key[m] != a[2]) {p2->ptr[m++] = p[n++];}
          p2->ptr[m++] = p[n++];p2->ptr[m++] = N;
          while(m<=p2->cnt)  p2->ptr[m++] = p[n++];
          S.push(p2);
        }
        else{
          int m=0,n=0;
          while(m<=p1->cnt) p1->ptr[m++] = p[n++];
          p2->ptr[0] = p[n++];
          m = 1;
          while(m<=p2->cnt) p2->ptr[m++] = p[n++];
          S.push(p1);
        }
      }

      else{
        //cout << "go" << z << "lo";
        int q=0;
        for(q;q<=P->cnt;q++) if(P->ptr[q] == T) break;
        if(z<q){
          addnum(P->key[z],P->ptr[z]);
          P->key[z] = P->ptr[z+1]->key[0];
          P->ptr[z]->ptr[P->ptr[z]->cnt] = P->ptr[z+1]->ptr[0];
          int i;
          for(i=0;i<P->ptr[z+1]->cnt-1;i++){
            P->ptr[z+1]->key[i] = P->ptr[z+1]->key[i+1];
            P->ptr[z+1]->ptr[i] = P->ptr[z+1]->ptr[i+1];
          }
          P->ptr[z+1]->ptr[i] = P->ptr[z+1]->ptr[i+1];
          P->ptr[z+1]->cnt = P->ptr[z+1]->cnt-1;
        }
        /*else{
          addnum(P->key[z-1],P->ptr[z]);
          P->key[z-1] = P->ptr[z-1]->key[P->ptr[z-1]->cnt-1];
          for(int i=P->ptr[z]->cnt;i>0;i--){
            P->ptr[z]->ptr[i] = P->ptr[z]->ptr[i-1];
          }
          P->ptr[z]->ptr[0] = P->ptr[z-1]->ptr[P->ptr[z-1]->cnt];
          P->ptr[z-1]->ptr[P->ptr[z-1]->cnt] = NULL;
          P->ptr[z-1]->cnt -= 1;
        }*/
        S.push(P);
        overflow(head,T,a,S,x);
      }
    }
  }
}

void add(ptr &head,ptr &T,int x,stack<ptr> &S){
  if(T == NULL){
    T = getnode(x);
    S.push(T);
    return;
  }

  if(isleaf(T)){
    if(T->cnt < 4){
      addnum(x,T);
      S.push(T);
    }

    else{
      int a[5];int flag = 0;
      int j = 0;
      for(int i=0;i<5;i++){
        if(j<4 && (T->key[j] < x || flag == 1)) {a[i] = T->key[j++];}
        else {a[i] = x;flag = 1;}
      }
      overflow(head,T,a,S,x);
    }
    return;
  }

  int i = 0;
  while(i<T->cnt){
    if(x<T->key[i]) break;
    i++;
  }
  S.push(T);

  add(head,T->ptr[i],x,S);
}

void printlevel(queue<ptr> &q){
  if(q.size() == 1) return;
  ptr t = q.front();q.pop();
  if(t == NULL){
    cout << endl;
    q.push(NULL);
    printlevel(q);
  }

  else{
    int i=0;
    cout << "{" ;
    while(i<t->cnt){
      if(t->ptr[i]) q.push(t->ptr[i]);
      cout << t->key[i] << " ";
      i++;
    }
    cout << "}" ;
    if(t->ptr[i]) q.push(t->ptr[i]);
  }
  printlevel(q);
}

int main(){
  ptr T = NULL;

  while(1){1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
    int x;cin >> x;
    if(x == -1) break;
    stack<ptr> S;
    add(T,T,x,S);
    while(S.size()!=1) S.pop();
    T = S.top();
  }
  queue<ptr> q;
  q.push(T);q.push(NULL);
  printlevel(q);

  cin.get();
  cin.get();
}

/*
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
*/
