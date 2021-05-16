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

int sum(vector<int> wei){
  int cnt = 0;
  for(int i=0;i<wei.size();i++) cnt+=wei[i];
  return cnt;
}

void find(int **a,int n,vector<int> &v,int &fsum,vector<int> &wei,vector<int> &temp,int par,int cur,int s,int d,int k,int i){
  if(i==k){
    if(par == s && cur == d)  {
      int x = sum(wei);
      if(x < fsum){
        fsum = x;
        v.clear();
        for(int i=0;i<temp.size();i++) v.push_back(temp[i]);
      }
    }
    return;
  }

  for(int j=0;j<n;j++){
    if(a[cur][j] > 0) {
      temp.pb(j);wei.push_back(a[cur][j]);
      find(a,n,v,fsum,wei,temp,par,j,s,d,k,i+1);
      temp.pop_back();wei.pop_back();
    }
  }
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
  }

  primat(a,n);
  cout << endl;

  cout << "Enter the value of s, d ,k." << endl;
  int k,s,d;cin >> s >> d >> k;
  vector<int> v;
  int fsum = INT_MAX;
  std::vector<int> temp,wei;
  temp.push_back(s);
  find(a,n,v,fsum,wei,temp,s,s,s,d,k,0);

  int i=0;
  for(i=0;i<v.size();i++){
    cout << v[i] << " ";
  }

  cin.get();
  cin.get();
  return 0;
}
