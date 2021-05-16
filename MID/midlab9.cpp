#include <bits/stdc++.h>
using namespace std;

struct gtnode;

union d{
  struct gtnode* ptr[27];
  char c[20];
};

bool compare( pair <string,int> p1,pair<string,int> p2){
  return p1.second>p2.second;
}

typedef struct gtnode{
  bool leaf;
  int cnt;
  union d u;
}* GTPTR;

GTPTR getnode(string s,int x){
  GTPTR temp = new gtnode;
  if(x==1){
    for(int i=0;i<s.size();i++) temp->u.c[i] = s[i];
  }
  else{
    for(int i=0;i<27;i++) temp->u.ptr[i] = NULL;
  }

  if(x==1){
    temp->leaf = true;
    temp->cnt = 1;
  }
  else{
    temp->leaf = false;
    temp->cnt = 0;
  }
  return temp;
}

int key(char c,vector<char> a){
  for(int i=0;i<a.size();i++) if(a[i]==c) return i;
}

GTPTR create(GTPTR T,string s,vector<char> a,int &i){
  if(i>s.size()) return NULL;
  if(T == NULL){
    T = getnode(s,1);
    return T;
  }
  else if(i==s.size() && T->leaf == false){
    if(T->u.ptr[a.size()])  T->u.ptr[a.size()]->cnt++;
    else T->u.ptr[a.size()] = getnode(s,1);
    return T;
  }
  else{
    int x = key(s[i],a);
    if(T->u.ptr[x] && T->u.ptr[x]->leaf){
      string s1 = "";
      int j = 0;
      int tem;
      while(T->u.ptr[x]->u.c[j] != '\0'){
        s1 += T->u.ptr[x]->u.c[j];
        tem = T->u.ptr[x]->cnt;
        j++;
      }
      if(s1 == s){
        T->u.ptr[x]->cnt++;
      }
      else{
        T->u.ptr[x] = NULL;
        T->u.ptr[x] = getnode(s1,0);
        int temp = i;
        for(int m=0;m<tem;m++) {T->u.ptr[x] = create(T->u.ptr[x],s1,a,++i);i=temp;}
        T->u.ptr[x] = create(T->u.ptr[x],s,a,++temp);
      }
    }

    else T->u.ptr[x] = create(T->u.ptr[x],s,a,++i);

    return T;
  }
}

void print(GTPTR T,int n){
  if(!T) return;
  if(T->leaf){
    int i=0;
    while(T->u.c[i]!='\0') {cout << T->u.c[i];i++;}
    cout << " " << T->cnt;
    cout << endl;
    return;
  }

  for(int i=0;i<=n;i++) {print(T->u.ptr[i],n);}
}

void updatem(GTPTR T,map<string,int, greater < string > > &M,int n){
  if(!T) return;
  if(T->leaf){
    int i=0;
    string temp = "";
    while(T->u.c[i]!='\0') {temp+=T->u.c[i];i++;}
    M[temp] = T->cnt;
    return;
  }

  for(int i=0;i<=n;i++) {updatem(T->u.ptr[i],M,n);}
}

int main(){
  GTPTR t = NULL;
  string temp = "";
  t = getnode(temp,0);
  cout << "Enter the alphabets in words." << endl;
  std::vector<char> a;
  while(1){
    char x;cin >> x;
    if(x=='0') break;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  cout << "Enter the strings" << endl;
  while(1){
    string s;cin >> s;
    if(s=="#") break;
    int i=0;
    t = create(t,s,a,i);
  }

  print(t,a.size());

  map<string,int, greater < string > > M;
  updatem(t,M,a.size());
  vector <pair<string, int> > mapcopy(M.begin(),M.end());
  sort(mapcopy.begin(), mapcopy.end(),compare);

  cout << "Enter the number of k." << endl;
  int k;cin>> k;

  for(int i=0;i<k;i++) cout << mapcopy[i].first << " " <<  mapcopy[i].second << endl;

  cin.get();
  cin.get();
  return 0;
}
