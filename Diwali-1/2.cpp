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

void assi(int **a,int w[],int d[],bool v[],int pv[],int n,int c){
  for(int i=0;i<n;i++){
    if(a[c][i] > 0 && v[i]==false){
      if(d[i] > d[c]+w[c]){
        d[i] = d[c]+w[c];
        pv[i] = c;
      }
    }
  }
  v[c] = true;
  int mini=1000,mind=1000;
  int i;
  for(i=0;i<n;i++){
    if(mind>d[i] && v[i]==false){mind = d[i];mini = i;}
  }
  if(mind == 1000) return;
  assi(a,w,d,v,pv,n,mini);
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  int w[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
  }

  cout << "Enter the weight of vertices." << endl;
  for(int i=0;i<n;i++){
    cout << "Enter weight of " << i << " : " ;
    int x;cin >> x;
    w[i] = x;
  }

  primat(a,n);cout << endl;

  int d[n] = {1000};
  for(int i=0;i<n;i++) d[i] = 1000;
  bool v[n] = {false};
  for(int i=0;i<n;i++) v[i] = false;
  int pv[n] = {-1};
  for(int i=0;i<n;i++) pv[i] = -1;
  cout << "Enter the start and end vertex." << endl;
  int st,en;
  cin >> st >> en;
  d[st] = 0;
  pv[st] = -1;
  assi(a,w,d,v,pv,n,st);

  vector<int> temp;
  int x = en;
  int sum = 0;
  while(x!=st){
    sum += d[x];
    temp.push_back(x);
    x = pv[x];
  }
  temp.push_back(st);
  cout << "SUM : " << d[en] << endl;
  for(int i=temp.size()-1;i>=0;i--) cout << temp[i] << " ";


  cin.get();
  cin.get();
  return 0;
}
/*0 1 
0 3
1 3
1 4
3 4
3 6
3 5
3 2
4 6
6 5
2 5
2 0 */
