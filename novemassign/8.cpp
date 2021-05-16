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

int sum(vector<int> wei){
  int cnt = 0;
  for(int i=0;i<wei.size();i++) cnt+=wei[i];
  return cnt;
}

void find(int **a,int n,vector<int> &temp,vector<int> &res,vector<int> &wei,int &fsum,int st,int en){
  if(st == en){
    int x = sum(wei);
    if(x<fsum){
      fsum = x;
      res = temp;
    }
    return;
  }

  for(int i=0;i<n;i++){
    if(a[st][i]>0 && !check(i,temp)){
      if(wei.size()<2){
        temp.push_back(i);wei.push_back(a[st][i]);
        find(a,n,temp,res,wei,fsum,i,en);
        temp.pop_back();wei.pop_back();
      }
      else if(wei[0]>wei[1] && wei[wei.size()-1]>a[st][i]){
        temp.push_back(i);wei.push_back(a[st][i]);
        find(a,n,temp,res,wei,fsum,i,en);
        temp.pop_back();wei.pop_back();
      }
      else if(wei[0]<wei[1] && wei[wei.size()-1]<a[st][i]){
        temp.push_back(i);wei.push_back(a[st][i]);
        find(a,n,temp,res,wei,fsum,i,en);
        temp.pop_back();wei.pop_back();
      }
    }
  }
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

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
    a[y][x] = w;
  }
  primat(a,n);cout << endl;
  cout << "Enter the start vertex." << endl;
  int k;cin >> k;

  vector<vector<int>> res;
  for(int i=0;i<n;i++){
    vector<int> temp,temp2,wei;
    int fsum = INT_MAX;
    if(i!=k){
      temp.push_back(k);
      find(a,n,temp,temp2,wei,fsum,k,i);
      res.push_back(temp2);
    }
  }

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++) cout << res[i][j] << " ";
    cout << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
