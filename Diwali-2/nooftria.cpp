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

int deg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++) cnt+=a[i][j];
  }
  return cnt;
}

void find(int **a,int n,int &cnt,int par,int cur,int k,int i){
  if(i==k){
    if(cur == par) cnt++;
    return;
  }

  for(int j=0;j<n;j++){
    if(a[cur][j] == 1) find(a,n,cnt,par,j,k,i+1);
  }
}
DiwaliDiwali
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
    a[y][x] = 1;
  }

  primat(a,n);
  cout << endl;

  int cnt = 0;
  for(int i=0;i<n;i++){
    find(a,n,cnt,i,i,3,0);
  }
  cout << "No. of triangles = " << cnt/6 << endl;

  cin.get();
  cin.get();
  return 0;
}
