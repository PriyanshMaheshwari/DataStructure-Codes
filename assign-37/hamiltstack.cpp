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

int deg(int **a,int n,int x){
  int cnt = 0;
  for(int j=0;j<n;j++) if(a[x][j] > 0)cnt+=1;

  return cnt;
}


bool hampath(int **a,int n,int res[],stack<int> &S,int l){
  if(S.size() == 0) return false;
  if(S.size() == n){
    for(int i=0;i<n;i++) if(res[i] == 0) return false;
    return true;
  }

  if(deg(a,n,l) == 0){
    l = S.top();S.pop();
    res[l] = 0;
    if(hampath(a,n,res,S,l)) return true;
  }
  else{
    for(int i=0;i<n;i++){
      if(a[l][i] == 1){
        a[l][i] = a[i][l] = -1;
        S.push(i);res[i] = 1;
        if(hampath(a,n,res,S,i)) return true;
      }
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
    int x,y,w;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
    a[y][x] = 1;
  }

  stack<int> S;
  int res[n];
  for(int i=0;i<n;i++) res[i] = 0;
  S.push(0);
  res[0] = 1;
  if(hampath(a,n,res,S,0)) cout << "Yes" << endl;
  else cout << "No" << endl;

  cin.get();
  cin.get();
  return 0;
}
