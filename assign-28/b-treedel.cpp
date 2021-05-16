#include <bits/stdc++.h>
using namespace std;

typedef struct bdnode{
  int cnt;
  int key[5];
  bdnode* ptr[6];
}* ptr;

int d = 2;

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
  if(i!=0 && P->ptr[i-1]->cnt > d) return 1;
  if(i!=P->cnt && P->ptr[i+1]->cnt > d) return 2;
  return 0;
}

void overflow(ptr&head,ptr &T,int a[],stack<ptr> &S){
  ptr N = getnode(a[3]);addnum(a[4],N);
  T->cnt = 2;
  T->key[0] = a[0];T->key[1] = a[1];
  if(S.size() == 0){
    ptr P = getnode(a[2]);
    P->ptr[0] = T;P->ptr[1] = N;
    S.push(P);
    return;
  }

  else{
    ptr P = S.top();S.pop();
    if(P->cnt != 4){
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
      int b[5];int flag = 0;
      int j = 0;
      for(int i=0;i<5;i++){
        if(j<4 && (P->key[j] < a[2] || flag == 1)) b[i] = P->key[j++];
        else {b[i] = a[2];flag = 1;}
      }
      ptr p[5];
      for(int k=0;k<5;k++) p[k] = P->ptr[k];

      overflow(head,P,b,S);
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
      overflow(head,T,a,S);
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

bool check(ptr T){
  if(T->cnt > d) return true;
  for(int i=0;i<=T->cnt;i++){
    if(check(T->ptr[i])) return true;
  }
  return false;
}

void removenum(ptr &T,int x){
  int i = 0;
  while(i<T->cnt) {if(T->key[i] == x)break;i++;}
  swap(T->key[i],T->key[T->cnt-1]);
  T->cnt--;
  sort(T->key,T->key+T->cnt);
}

void merge(ptr &P,int q){
  ptr temp = getnode(P->ptr[q]->key[0]);
  for(int i=1;i<P->ptr[q]->cnt;i++) addnum(P->ptr[q]->key[i],temp);
  for(int i=0;i<P->ptr[q+1]->cnt;i++) addnum(P->ptr[q+1]->key[i],temp);
  addnum(P->key[q],temp);
  for(int i=q;i<P->cnt;i++){
    P->key[i] = P->key[i+1];
    P->ptr[i] = P->ptr[i+1];
  }
  P->ptr[q] = temp;
  P->cnt-=1;
}

void merge2(ptr &P,int q){
  ptr temp = getnode(P->ptr[q]->key[0]);
  for(int i=1;i<P->ptr[q]->cnt;i++) addnum(P->ptr[q]->key[i],temp);
  for(int i=0;i<P->ptr[q+1]->cnt;i++) addnum(P->ptr[q+1]->key[i],temp);
  for(int i=q;i<P->cnt;i++){
    P->key[i] = P->key[i+1];
    P->ptr[i] = P->ptr[i+1];
  }
  P->ptr[q] = temp;
  P->cnt-=1;
}

void merge3(ptr &P,int q){
  ptr temp = getnode(P->ptr[q]->key[0]);
  for(int i=1;i<P->ptr[q]->cnt;i++) addnum(P->ptr[q]->key[i],temp);
  for(int i=0;i<P->ptr[q+1]->cnt;i++) addnum(P->ptr[q+1]->key[i],temp);
  addnum(P->key[q],temp);
  if(P->cnt!=1){
  for(int i=q;i<P->cnt;i++){
    P->key[i] = P->key[i+1];
    P->ptr[i] = P->ptr[i+1];
  }}
  int j=0;
  for(int i=0;i<=P->ptr[q]->cnt;i++) temp->ptr[j++]=P->ptr[q]->ptr[i];
  for(int i=0;i<=P->ptr[q+1]->cnt;i++) temp->ptr[j++]=P->ptr[q+1]->ptr[i];

  P->ptr[q] = temp;
  P->cnt-=1;

  P = P->ptr[q];
}

bool seaover(ptr T,stack<int> &S2){
  for(int i=0;i<=T->cnt;i++){
    if(isleaf(T->ptr[i]) && T->ptr[i]->cnt>d){
      S2.push(i);
      return true;
    }
    else if(!isleaf(T->ptr[i])){
      S2.push(i);
      if(seaover(T->ptr[i],S2)) return true;
      else S2.pop();
    }
  }
  return false;
}

void del(ptr &T,int x,stack<ptr> &S){
  if(isleaf(T)){
    if(T->cnt > d || S.size()==0) {
      removenum(T,x);
      S.push(T);
      return;
    }
    else{
      ptr P = S.top();S.pop();
      int q=0;
      for(q;q<=P->cnt;q++) if(P->ptr[q]->key[0] == T->key[0]) break;
      if(isemp(T,P) == 1){
        addnum(P->key[q-1],T);
        P->key[q-1] = P->ptr[q-1]->key[P->ptr[q-1]->cnt-1];
        P->ptr[q-1]->cnt -= 1;
        removenum(T,x);
        S.push(P);
      }
      else if(isemp(T,P) == 2){
        addnum(P->key[q],T);
        P->key[q] = P->ptr[q+1]->key[0];
        removenum(P->ptr[q+1],P->ptr[q+1]->key[0]);
        removenum(T,x);
        S.push(P);
      }
      else{
        if(P->cnt == 1 && S.size()!=0){
          removenum(T,x);
          if(q!=P->cnt) {merge(P,q);}
          else {merge(P,q-1);}
          S.push(T);
        }
        else if(P->cnt>d || S.size()==0){
          removenum(T,x);
          if(q!=P->cnt) {merge(P,q);}
          else {merge(P,q-1);}
          S.push(P);
        }
        else{
          if(q!=P->cnt){
            addnum(P->key[q],T);
            P->key[q] = x;
            removenum(T,x);
            del(P,x,S);
          }
          else{
            addnum(P->key[q-1],T);
            P->key[q-1] = x;
            removenum(T,x);
            del(P,x,S);
          }
        }
      }
    }
  }
  else{
    int q=0;
    for(q;q<=T->cnt;q++) if(T->key[q] == x) break;
    if(isleaf(T->ptr[q+1]) && isleaf(T->ptr[q])){
      if(T->ptr[q+1]->cnt > d){
        swap(T->ptr[q+1]->key[0],T->key[q]);
        S.push(T);
        del(T->ptr[q+1],x,S);
      }
      else if(T->ptr[q]->cnt > d){
        swap(T->ptr[q]->key[T->ptr[q]->cnt-1],T->key[q]);
        S.push(T);
        del(T->ptr[q],x,S);
      }
      else{
        merge2(T,q);
        if(S.size()!=0){
          ptr P = S.top();S.pop();
          int q2=0;
          for(q2;q2<=P->cnt;q2++) if(P->ptr[q2]->key[0] == T->key[0]) break;
          if(q2!=P->cnt) merge3(P,q2);
          else merge3(P,q2-1);
          S.push(P);
        }
        S.push(T);
      }
    }
    else if(S.size()>0){
      ptr P = S.top();S.pop();
      int q2=0;
      for(q2;q2<=P->cnt;q2++) if(P->ptr[q2]->key[0] == T->key[0]) break;
      if(isemp(T,P) == 1){
        ptr temp = P->ptr[q2-1];
        stack<ptr> S2;
        S2.push(P->ptr[q2-1]);
        while(!isleaf(temp)) {S2.push(temp);temp=temp->ptr[temp->cnt];}
        int z = P->key[q2-1];
        P->key[q2-1] = temp->key[temp->cnt-1];
        del(temp,temp->key[temp->cnt-1],S2);
        ptr temp2 = T;
        while(!isleaf(temp2)) temp2 = temp2->ptr[0];
        addnum(z,temp2);
      }
      else if(isemp(T,P) == 2){
        ptr temp = P->ptr[q2+1];
        stack<ptr> S2;
        while(!isleaf(temp)) {S2.push(temp);temp=temp->ptr[temp->cnt];};
        int z = P->key[q2];
        P->key[q2] = temp->key[0];
        del(temp,temp->key[0],S2);
        ptr temp2 = T;
        while(!isleaf(temp2)) temp2 = temp2->ptr[temp->cnt];
        addnum(z,temp2);
      }
      S.push(P);
      del(T,x,S);
    }
    else if(check(T->ptr[q])){
      swap(T->ptr[q]->key[T->ptr[q]->cnt-1],T->key[q]);
      S.push(T);
      del(T->ptr[q],x,S);
    }
    else if(check(T->ptr[q+1])){
      swap(T->ptr[q+1]->key[0],T->key[q]);
      S.push(T);
      del(T->ptr[q+1],x,S);
    }
    else{
      merge2(T,q);
    }
  }
}

void delsea(ptr &T,int x,stack<ptr> &S){

  if(!T){return;}

  int i;
  for(i=0;i<T->cnt;i++){
     if(T->key[i]==x){del(T,x,S) ;}
     if(T->key[i] > x)break;
   }
   S.push(T);
   delsea(T->ptr[i],x,S);
}

int main(){
  ptr T = NULL;

  while(1){
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
  cout << endl;

  while(1){
    cout << "Enter the no. you want to delete." << endl;
    int x;cin >> x;
    if(x==-1) break;
    stack<ptr> S;
    delsea(T,x,S);
    while(S.size()!=1) S.pop();
    T = S.top();
    if(T->cnt == 0) T = NULL;
    queue<ptr> q1;
    q1.push(T);q1.push(NULL);
    printlevel(q1);
  }

  cin.get();
  cin.get();
  return 0;
}
