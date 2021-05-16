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

int deg(int **a,int n){
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) if(a[i][j] == 1) cnt++;
  }
  return cnt;
}

int indeg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++) if(a[i][x] == 1) cnt++;
  return cnt;
}

int outdeg(int **a,int n,int x){
  int cnt = 0;
  for(int i=0;i<n;i++) if(a[x][i] == 1) cnt++;
  return cnt;
}

void maxsum(int **a,int w[],int n,int cur,int sum,int &max){
  if(sum > max) max = sum;

  for(int i=0;i<n;i++){
    if(a[cur][i] == 1){
      maxsum(a,w,n,i,sum+w[i],max);
    }
  }
}

void kpath(int **a,int w[],vector<vector<int>> &res,vector<int> &temp,int n,int cur,int sum,int k){
  if(sum == k){res.push_back(temp);}

  for(int i=0;i<n;i++){
    if(a[cur][i] == 1){
      temp.push_back(i);
      kpath(a,w,res,temp,n,i,sum+w[i],k);
      temp.pop_back();
    }
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  for(int i=0;i<n;i++){
    cout << "Enter neighbour of " << i << " : ";
    while(1){
      int x;cin >> x;
      if(x==-1) break;
      a[i][x] = 1;
    }
  }

  primat(a,n);
  cout << endl;
  int w[n];
  cout << "Enter the weight of vertices." << endl;
  for(int i=0;i<n;i++){
    cout << "Enter weight of " << i << " : " ;
    int x;cin >> x;
    w[i] = x;
  }

  int ma=0;
  for(int i=0;i<n;i++){
    maxsum(a,w,n,i,w[i],ma);
  }

  cout << "MAX SUM : " << ma << endl;
  cout << "Enter the value of k." << endl;
  int k;cin >> k;

  vector<vector<int>> res;
  for(int i=0;i<n;i++){
    std::vector<int> temp;
    temp.push_back(i);
    kpath(a,w,res,temp,n,i,w[i],k);
  }

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++) cout << res[i][j] << " ";
    cout << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
