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

int indeg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++) if(a[i][x] == 1) cnt++;
  return cnt;
}

int outdeg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++) if(a[x][i] == 1) cnt++;
  return cnt;
}

void toposort(int **a,int n,int o[],int in[],bool f[]){
  static int l = 0;
  int i;
  vector<int> x;
  for(i=0;i<n;i++){
    if(in[i] == 0 && f[i] == false){
      o[i] = max(o[i],l);
      f[i] = true;
      x.push_back(i);
    }
  }
  l++;
  if(x.size() == 0) return;
  for(int h=0;h<x.size();h++){
    i = x[h];
    for(int j=0;j<n;j++){
      if(a[i][j] == 1) in[j]--;
    }
  }
  toposort(a,n,o,in,f);
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
  }

  primat(a,n);
  int o[n];
  for(int i=0;i<n;i++) o[i] = -1;

  int in[n];
  for(int i=0;i<n;i++) in[i]  = indeg(a,n,i);
  bool f[n] = {false};
  cout << endl;
  toposort(a,n,o,in,f);

  for(int i=0;i<n;i++){
    cout << i << " : " << o[i] << endl;
  }

  cin.get();
  cin.get();
  return 0;
}

/*
0 1
1 2
2 3
3 4
5 6
6 7
7 2
-1 -1
*/
