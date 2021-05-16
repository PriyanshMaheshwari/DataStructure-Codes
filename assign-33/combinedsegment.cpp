#include <bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    L = T;
}

void add(int x,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;
    T1->next = T;
    T->next = NULL;
}

void printl(LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    while(T!=NULL){
        cout << T->data << " ";
        T = T->next;
    }
}

void deletebegin(LPTR &L){
    L = L->next;
}

void del(int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){deletebegin(L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T = T1->next;
    T1->next = T->next;
    delete(T);
}

int create(LPTR H[],LPTR a[],int f,int n,int i){
  if(i>=2*n-1){
    switch(f){
      case 0 :
      return 0;
      case 1 :
      return INT8_MAX;
      case 2 :
      return INT8_MIN;
    }
  }
  if(i>=n-1){
    LPTR temp = a[i-n+1];
    for(int  j=0;j<f;j++) temp = temp->next;
    add(temp->data,H[i]);
    return temp->data;
  }
  else{
    int x;
    switch(f){
      case 0 :
      x = create(H,a,f,n,2*i+1)+create(H,a,f,n,2*i+2) ;
      break;
      case 1 :
      x = min(create(H,a,f,n,2*i+1),create(H,a,f,n,2*i+2));
      break;
      case 2 :
      x = max(create(H,a,f,n,2*i+1),create(H,a,f,n,2*i+2));
      break;
    }
    add(x,H[i]);
    return x;
  }
}

int range(LPTR H[],int h,int mi,int ma,int k,int i,int j,int n,int f){
  int x;
  switch(f){
    case 0 :
    x = 0;
    break;
    case 1 :
    x =  INT8_MAX;
    break;
    case 2 :
    x = INT8_MIN;
    break;
  }
  if(i>j) return x;
  if(k>=2*h-1) return x;

  if(i>ma || j<mi) return x;
  else if(i>=mi && j<=ma) {
    LPTR temp = H[k];
    for(int l=0;l<f;l++) temp = temp->next;
    return temp->data;
  }
  else{
    switch(f){
      case 0 :
      return range(H,h,mi,ma,2*k+1,i,(i+j-1)/2,n,f)+range(H,h,mi,ma,2*k+2,(i+j-1)/2+1,j,n,f);
      case 1 :
      return min(range(H,h,mi,ma,2*k+1,i,(i+j-1)/2,n,f),range(H,h,mi,ma,2*k+2,(i+j-1)/2+1,j,n,f));
      case 2 :
      return max(range(H,h,mi,ma,2*k+1,i,(i+j-1)/2,n,f),range(H,h,mi,ma,2*k+2,(i+j-1)/2+1,j,n,f));
    }
  }
}

int main()
{
  cout << "Enter the number of values." << endl;
  int n;cin >> n;
  int h=0;
  while(pow(2,h) < n) h++;
  h = pow(2,h);
  LPTR a[h];
  for(int i=0;i<h;i++) a[i] = NULL;

  cout << "Enter the values." << endl;
  int i;
  for(i=0;i<n;i++){
    int x;
    cin >> x;
    add(x,a[i]);
    add(x,a[i]);
    add(x,a[i]);
  }
  for(i;i<h;i++){
    add(0,a[i]);
    add(INT8_MAX,a[i]);
    add(INT8_MIN,a[i]);
  }
  LPTR H[2*h-1] = {NULL};
  int sum =  create(H,a,0,h,0);
  int mi = create(H,a,1,h,0);
  int m2 = create(H,a,2,h,0);

  while(1){
    cout << "Enter 0 for sum" << endl;
    cout << "Enter 1 for min" << endl;
    cout << "Enter 2 for max" << endl;
    cout << "Enter -1 to exit" << endl;
    int f;cin >> f;
    if(f==-1) break;
    cout << "Enter the range " << endl;
    int mi,ma;
    cin >> mi >> ma;
    cout << range(H,h,mi,ma,0,1,h,n,f) << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
