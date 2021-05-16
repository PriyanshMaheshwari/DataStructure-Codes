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

bool check(int x,vector<int> temp){
  for(int i=0;i<temp.size();i++) if(temp[i] == x) return false;
  return true;
}

void toposort(int **a,vector<vector<int> > &res,vector<int> &temp,int n,int in[]){
  if(temp.size() == n){
    res.push_back(temp);
    return;
  }
  int i;
  for(i=0;i<n;i++){
    if(in[i] == 0  && check(i,temp)){
      temp.push_back(i);
      vector<int> x;
      for(int j=0;j<n;j++){
        if(a[i][j] == 1) {in[j]--;x.push_back(j);}
      }
      toposort(a,res,temp,n,in);
      temp.pop_back();
      for(int j=0;j<x.size();j++){
        in[x[j]]++;
      }
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
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
  }

  primat(a,n);
  vector<vector<int> > res;
  vector<int> temp;
  int in[n];
  for(int i=0;i<n;i++) in[i]  = indeg(a,n,i);
  bool f[n] = {false};
  cout << endl;
  toposort(a,res,temp,n,in);
  cout << "No. of ways : " << res.size() << endl;

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  cout << "No. of ways : " << res.size() << endl;
  cin.get();
  cin.get();
  return 0;
}
