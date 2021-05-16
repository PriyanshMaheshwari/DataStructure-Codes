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

bool compare( pair <int,int> p1,pair <int,int>  p2){
  return p1.second>p2.second;
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

void pridf(int **a,vector<int> &temp,int n,int k,bool vis[]){
  temp.pb(k);
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp) && !vis[i]){
      pridf(a,temp,n,i,vis);
    }
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  int **r = new int*[n];
  int ar[n],de[n];
  for(int i=0;i<n;i++) a[i] = new int[n];
  for(int i=0;i<n;i++) r[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;r[y][x] = 1;
  }

  vector<int> temp;
  for(int i=0;i<n;i++){
    if(!check(i,temp)) pridfs(a,ar,de,temp,n,i);
  }

  vector<pair<int,int>> v;
  for(int i=0;i<n;i++) v.push_back(make_pair(i,de[i]));
  sort(v.begin(),v.end(),compare);

  vector<vector<int>> z;
  bool vis[n];
  for(int i=0;i<n;i++) vis[i] = false;

  for(int i=0;i<n;i++){
    if(!vis[v[i].first]){
      vector<int> temp2;
      pridf(r,temp2,n,v[i].first,vis);
      for(int i=0;i<temp2.size();i++) vis[temp2[i]] = true;
      z.push_back(temp2);
      temp2.clear();
    }
  }

  for(int i=0;i<z.size();i++){
    for(int j=0;j<z[i].size();j++) cout << z[i][j] << " ";
    cout << endl;
  }

  cin.get();
  cin.get();
  return 0;
}

/*
0 1
0 3
1 2
1 5
2 0
2 3
2 4
3 4
5 2
6 5
6 7
7 5
7 9
8 7
9 8
-1 -1
*/

/*
0 2
1 0
2 1
0 3
3 4
-1 -1
*/
