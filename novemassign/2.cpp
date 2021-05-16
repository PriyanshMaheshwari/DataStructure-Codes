#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool check(int t,vector<int> a){
  for(int i=0;i<a.size();i++) if(a[i] == t) return true;
  return false;
}

bool connect(int **a,int n,vector<int> &temp,int i){
  temp.push_back(i);
  if(temp.size() == n) return true;
  for(int k=0;k<n;k++){
    if(a[i][k]>0 && !check(k,temp))
      if(connect(a,n,temp,k)) return true;
  }
  return false;
}

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

bool compare( pair <pair<int,int>,int> p1,pair <pair<int,int>,int>  p2){
  return p1.second>p2.second;
}

int indeg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++) if(a[i][x] == 1) cnt++;
  return cnt;
}


int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  int S[n];
  for(int i=0;i<n;i++) S[i] = -1;
  vector<pair<pair<int,int>,int>> v;

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
    a[y][x] = w;
    v.push_back(make_pair(make_pair(x,y),w));
  }

  sort(v.begin(),v.end(),compare);

  int i = 0;
  while(i<v.size()){
    int x = v[i].first.first;
    int y = v[i].first.second;

    a[x][y] = 0;a[y][x] = 0;
    vector<int> temp;
    if(!connect(a,n,temp,0)){
      a[x][y] = a[y][x] = v[i].second;
    }

    i++;
  }

  primat(a,n);

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
