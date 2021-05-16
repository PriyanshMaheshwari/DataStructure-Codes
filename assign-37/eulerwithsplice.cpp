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

int deg(int **a,int n,int x){
  int cnt = 0;
  for(int j=0;j<n;j++) if(a[x][j] > 0)cnt+=1;

  return cnt;
}

void euler(int **a,int n,int l,int par,vector<int> &res){
    if(deg(a,n,par) == 0) return;
    if(deg(a,n,l) != 0){
      res.push_back(l);
      if(deg(a,n,par) == 0) return;
      for(int j=0;j<n;j++){
        if(a[l][j] == 1){
          if(deg(a,n,par) == 0) return;
          a[l][j] = a[j][l] = -1;
          euler(a,n,j,par,res);
        }
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
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
    a[y][x] = 1;
  }

  primat(a,n);
  cout << endl;
  vector<int> res;

  res.push_back(0);
  int i=0;
  while(1){
    vector<int> temp;
    euler(a,n,res[i],res[i],temp);
    for(int j=0;j<temp.size();j++){
      if(i+j < res.size())res.insert(res.begin()+i+j,temp[j]);
      else res.push_back(temp[j]);
    }
    int j;
    for(int h=0;h<res.size();h++) cout << res[h] << " ";
    cout << endl;
    for(j=0;j<res.size();j++) {if(deg(a,n,res[j]) != 0){i = j;break;}}
    if(j == res.size()) break;
  }

  for(int i=0;i<res.size();i++) cout << res[i] << " ";
  cout << endl;

  cin.get();
  cin.get();
  return 0;
}

/*
0 2
0 3
1 2
1 7
2 5
2 8
2 6
2 3
3 4
3 10
3 9
3 6
4 9
5 8
6 8
6 9
7 8
8 9
8 11
9 10
9 11
*/

/*
0 1
0 4
0 5
0 6
1 4
1 3
1 2
2 3
3 4
3 5
4 5
5 6
-1 -1
*/
