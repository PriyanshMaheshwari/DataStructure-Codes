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

void pribfs(int **a,queue<int> &q,vector<int> &temp,int n){
  if(q.empty()) return;

  int k = q.front();q.pop();
  temp.pb(k);
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      v.pb(make_pair(i,a[k][i]));
    }
  }
  sort(v.begin(),v.end(),compare);
  for(int i=0;i<v.size();i++) q.push(v[i].first);

  pribfs(a,q,temp,n);
}

void assi(int **a,int d[],bool v[],int pv[],int n,int c){
  for(int i=0;i<n;i++){
    if(a[c][i] > 0 && v[i]==false){
      if(d[i] > d[c]+a[c][i]){
        d[i] = d[c]+a[c][i];
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
  assi(a,d,v,pv,n,mini);
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
    a[y][x] = w;
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
  assi(a,d,v,pv,n,st);

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
  cout << endl;

  for(int i=0;i<n;i++) d[i] = 1000;
  for(int i=0;i<n;i++) v[i] = false;
  for(int i=0;i<n;i++) pv[i] = -1;
  for(int i=1;i<temp.size()-1;i++) v[temp[i]] = true;
  d[st] = 0;
  pv[st] = -1;
  assi(a,d,v,pv,n,st);

  temp.clear();
  x = en;
  sum = 0;
  while(x!=st){
    sum += d[x];
    temp.push_back(x);
    x = pv[x];
  }
  temp.push_back(st);
  cout << "SUM : " << d[en] << endl;
  for(int i=temp.size()-1;i>=0;i--) cout << temp[i] << " ";
  cout << endl;

  cin.get();
  cin.get();
  return 0;
}

/*0 1 2
0 3 1
1 3 3
1 4 10
3 4 7
3 6 4
3 5 8
3 2 2
4 6 6
6 5 1
2 5 5
2 0 4*/
