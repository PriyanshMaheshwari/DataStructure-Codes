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

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind and its weight." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
  }
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
  queue<int> q;
  q.push(st);
  v[st] = true;

  while(!q.empty()){
    int c = q.front();q.pop();
    for(int i=0;i<n;i++){
      if(a[c][i] > 0){
        if(d[i] > d[c]+a[c][i]){
          d[i] = d[c]+a[c][i];
          pv[i] = c;
        }
        if(!v[i]){
          v[i] = true;
          q.push(i);
        }
      }
    }
  }


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
/*0 1 2
0 3 1
1 3 3
1 4 10
3 4 2
3 6 4
3 5 8
3 2 2
4 6 6
6 5 1
2 5 5
2 0 4*/
