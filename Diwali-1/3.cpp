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

void find(int **a,int n,vector<vector<int>> &v,int par,int cur,int k,int i){
  if(i==k){
    vector<int> temp;
    temp.push_back(par);temp.push_back(cur);
    v.push_back(temp);return;
  }

  for(int j=0;j<n;j++){
    if(a[cur][j] == 1) find(a,n,v,par,j,k,i+1);
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
  cout << endl;

  cout << "Enter the value of k." << endl;
  int k;cin >> k;
  vector<vector<int>> v;
  for(int i=0;i<n;i++){
    find(a,n,v,i,i,k,0);
  }
  sort(v.begin(),v.end());

  int i=0;
  while(i<v.size()-1){
    if(v[i] == v[i+1]) v.erase(v.begin()+i);
    else i++;
  }

  for(i=0;i<v.size();i++){
    cout << "(" << v[i][0] << "," << v[i][1] << ")" << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
