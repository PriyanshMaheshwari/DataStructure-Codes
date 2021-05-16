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

bool compare( pair <int,int> p1,pair<int,int> p2){
  return p1.second>p2.second;
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

void pridfs(int **a,int ar[],int de[],vector<int> &temp,int n,int k){
  static int i = 0;
  ar[k] = i++;
  temp.pb(k);
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      pridfs(a,ar,de,temp,n,i);
    }
  }
  de[k] = i++;
}

void toposort(int **a,int de[],int n){
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++){
    pair<int,int> p;
    p.first = i;p.second = de[i];
    v.push_back(p);
  }
  sort(v.begin(),v.end(),compare);
  for(int i=0;i<n;i++){
    cout << v[i].first << " ";
  }
  cout << endl;
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  int ar[n],de[n];
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

  vector<int> temp;
  for(int i=0;i<n;i++){
    if(!check(i,temp)) pridfs(a,ar,de,temp,n,i);
  }

  for(int i=0;i<n;i++){
    cout << i << " : (" << ar[i] << "," << de[i] << ")" << endl;
  }

  toposort(a,de,n);

  cin.get();
  cin.get();
  return 0;
}
