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

bool cycle(int **a,int n,int &i,vector<int> &v){
  for(int j=0;j<n;j++){
    if(a[i][j] == 1){
      v.push_back(i);
      for(int k=0;k<v.size();k++) if(v[k] == j){
        return true;
      }
      if(cycle(a,n,j,v)) return true;
      v.pop_back();
    }
  }
  return false;
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
  vector<int> v;
  int i;
  for(i=0;i<n;i++){
    if(cycle(a,n,i,v)) {
      cout << "Yes! there is a cycle." << endl;
      break;
    }
  }
  if(i == n) cout << "No! there are no cycle." << endl;

  cin.get();
  cin.get();
  return 0;
}
