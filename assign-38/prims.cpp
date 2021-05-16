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
  return p1.second<p2.second;
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

void pribfs(int **a,vector<pair<int,int>> &v,vector<int> &temp,int &sum,int n){
  if(temp.size() == n) return;
  int k;
  int h =0;
  while(h<v.size()){
    if(!check(v[h].first,temp)) {k = v[h].first;sum += v[h].second;break;}
    h++;
  }
  temp.pb(k);
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      v.pb(make_pair(i,a[k][i]));
    }
  }
  sort(v.begin(),v.end(),compare);

  pribfs(a,v,temp,sum,n);
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

  primat(a,n);
  cout << endl;

  vector<int> temp;
  vector<pair<int,int>> v;
  v.push_back(make_pair(0,0));
  int sum = 0;
  pribfs(a,v,temp,sum,n);

  for(int i=0;i<temp.size();i++) cout << temp[i] << " ";
  cout << endl;
  cout << "SUM : " << sum << endl;

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
