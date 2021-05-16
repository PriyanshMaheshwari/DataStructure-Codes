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

void hampath(int **a,int n,vector<int> &res,int cnt){
  if(res.size() == n){
    int i;
    for(i=0;i<n-1;i++){
      if(!a[res[i]][res[i+1]]) break;
    }
    if(i == n-1){
      for(int h=0;h<res.size();h++) cout << res[h] << " ";
      cout << endl;
    }
    return;
  }

  for(int i=0;i<n;i++){
    if(!check(i,res)){
      res.push_back(i);
      hampath(a,n,res,0);
      res.pop_back();
    }
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
    a[y][x] = 1;
  }

  vector<int> res;
  hampath(a,n,res,0);

  cin.get();
  cin.get();
  return 0;
}
