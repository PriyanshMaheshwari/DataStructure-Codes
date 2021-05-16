#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int sfind(int s[],int x){
  if(s[x] < 0) return x;
  return sfind(s,s[x]);
}

void uni(int S[],int x,int y){
  if(S[x] == -1&&S[y] == -1){
    S[y] = x;S[x]--;
  }
  else{
    int a = sfind(S,x);
    int b = sfind(S,y);
    if(a==b) return;
    else if(S[a] <= S[b]){
      S[a] = S[a]+S[b];
      S[b] = a;
    }
    else{
      S[b] = S[a]+S[b];
      S[a] = b;
    }
  }
}

bool find(int S[],int x,int y){
  if(x == y) return true;
  if(sfind(S,x) == sfind(S,y)) return true;
  return false;
}

bool allsame(int S[],int n){
  for(int i=0;i<n-1;i++) {if(sfind(S,i) != sfind(S,i+1)) return false;}
  return true;
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


int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  int S[n];
  for(int i=0;i<n;i++) S[i] = -1;
  int **p = new int*[n];
  for(int i=0;i<n;i++) p[i] = new int[n];

  vector<pair<pair<int,int>,int>> v;
  int sum = 0;

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
    a[y][x] = w;
    v.push_back(make_pair(make_pair(x,y),w));
  }

  for(int i=0;i<n;i++){
    int min=INT_MAX;int mini;
    for(int j=0;j<n;j++){
      if(a[i][j] > 0 && min>a[i][j]){
        min = a[i][j];mini = j;
      }
    }
    p[mini][i] = a[i][mini];
    p[i][mini] = a[i][mini];
    sum += a[i][mini];
    uni(S,i,mini);
  }


  map<pair<int,int>,int> m;
  vector<pair<pair<int,int>,int>> temp;

  std::vector<int> v2;
  for(int i=0;i<n;i++) if(S[i] < 0)v2.push_back(i);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++) m[{i,j}] = 0;
  }

  for(int i=0;i<v.size();i++){
    if(sfind(S,v[i].first.first) == sfind(S,v[i].first.second)){v.erase(v.begin()+i);i--;}
    else{
      int x = sfind(S,v[i].first.first);
      int y = sfind(S,v[i].first.second);

      if(m[{x,y}] > v[i].second){
        m[{x,y}] = v[i].second;
      }
    }
  }

  copy(m.begin(),m.end(),temp.begin());
  sort(temp.begin(),temp.end(),compare);
  int i=0;

  while(!allsame(S,n) && i<temp.size()){
    int x = temp[i].first.first;
    int y = temp[i].first.second;
    if(sfind(S,x) != sfind(S,y)){
      sum += temp[i].second;
      uni(S,x,y);
      i++;
    }
  }

  cout << "Sum : " << sum << endl;

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
2 0 4
-1 -1 -1
*/
