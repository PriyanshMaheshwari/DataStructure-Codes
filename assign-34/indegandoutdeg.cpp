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

int deg(int **a,int n){
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) if(a[i][j] == 1) cnt++;
  }
  return cnt;
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

  cout << "Degree of the graph : " << deg(a,n) << endl;;

  while(1){
    cout << "Enter the number whose degree you want to find." << endl;
    int x;cin >> x;
    if(x == -1) break;
    cout << "INDEG : " << indeg(a,n,x) << endl;
    cout << "OUTDEG : " << outdeg(a,n,x) << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
