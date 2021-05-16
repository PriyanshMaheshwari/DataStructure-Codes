#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void primat(int **a,int n){
  cout << "  ";
  for(int i=0;i<n;i++) cout << i << " ";
  cout << endl;
  for(int i=0;i<n;i++){
    cout << i << " ";
    for(int j=0;j<n;j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
bool check(int t,vector<int> a){
  for(int i=0;i<a.size();i++) if(a[i] == t) return true;
  return false;
}

int deg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++) cnt+=a[i][j];
  }

  return cnt;
}

void pridfs(int **a,int num[],int low[],vector<int> &temp,int n,int k,int par,vector<int> &res,int pv){
  static int o = 0;
  num[k] = o++;
  if(low[k] == -1) low[k] = num[k];
  temp.pb(k);int x = 0;
  vector<int> h;
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      if(k == par) x++;
      pridfs(a,num,low,temp,n,i,par,res,k);
      h.push_back(i);
      low[k] = min(low[k],low[i]);
    }
    else if(a[k][i] > 0 && check(i,temp)){
      low[k] = min(low[k],num[i]);
    }
  }

  o++;

  if(x>1) res.push_back(k);
  else if(k != par){
    for(int i=0;i<h.size();i++){
      if(low[h[i]] >= num[k]) {res.push_back(k);break;}
    }
  }
}

void comp(int **a ,int n, vector<int> &v,vector<int> &v2,int st,int par){
  if(st == par && v.size() > 0){
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
  }
  for(int i=0;i<n;i++){
    if(a[st][i]>0 && !check(i,v) && !check(i,v2)){
      v.push_back(i);v2.push_back(i);
      comp(a,n,v,v2,i,par);
      v.pop_back();
    }
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  int num[n],low[n];
  for(int i=0;i<n;i++) low[i] = -1;
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
    a[y][x] = 1;
  }

  vector<int> temp,res;
  pridfs(a,num,low,temp,n,0,0,res,-1);
  sort(res.begin(),res.end());

  for(int i=0;i<res.size();i++){
    vector<int> v,v2;
    comp(a,n,v,v2,res[i],res[i]);
  }

  cin.get();
  cin.get();
  return 0;
}

/*
0 1
0 2
1 2
1 4
1 3
3 4
3 5
4 5
5 6
5 7
6 7
-1 -1
*/
