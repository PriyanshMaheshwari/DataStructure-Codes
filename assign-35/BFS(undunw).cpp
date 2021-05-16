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

bool check(int t,vector<int> a){
  for(int i=0;i<a.size();i++) if(a[i] == t) return true;
  return false;
}

void pribfs(int **a,queue<int> &q,vector<int> &temp,int n){
  if(q.empty()) return;

  int k = q.front();q.pop();
  temp.pb(k);
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      q.push(i);
    }
  }
  pribfs(a,q,temp,n);
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
    a[y][x] = 1;
  }

  primat(a,n);
  cout << endl;
  cout << "Enter the number whose bfs you need." << endl;
  int k;cin >> k;

  queue<int> q;
  q.push(k);
  vector<int> temp;
  pribfs(a,q,temp,n);

  for(int i=0;i<temp.size();i++) cout << temp[i] << " ";

  cin.get();
  cin.get();
  return 0;
}
