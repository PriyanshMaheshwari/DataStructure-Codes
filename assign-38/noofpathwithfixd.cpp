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

void find(int **a,int n,vector<vector<int>> &v,std::vector<int> &temp,int par,int cur,int s,int d,int k,int i){
  if(i==k){
  if(par == s && cur == d)  {
    v.push_back(temp);
  }
    return;
  }

  for(int j=0;j<n;j++){

    if(a[cur][j] == 1) {
      temp.pb(j);
      find(a,n,v,temp,par,j,s,d,k,i+1);
      temp.pop_back();
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
  cout << endl;

  cout << "Enter the value of s, d ,k." << endl;
  int k,s,d;cin >> s >> d >> k;
  vector<vector<int>> v;
  std::vector<int> temp;
  temp.push_back(s);
    find(a,n,v,temp,s,s,s,d,k,0);
  sort(v.begin(),v.end());

  int i=0;

  for(i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++) cout << v[i][j];
    cout << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
