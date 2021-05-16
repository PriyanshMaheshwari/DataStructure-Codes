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

void find(int **a,int n,int st,int en,vector<int> &temp,vector<int> &wei,vector<int> &fin,int &tsum,int &fsum){
  if(st == en){
    int x = *max_element(wei.begin(),wei.end());
    if(tsum-x < fsum){
      fsum = tsum-x;
      fin.clear();
      for(int i=0;i<temp.size();i++) fin.push_back(temp[i]);
    }
    return;
  }

  for(int i=0;i<n;i++){
    if(a[st][i]>0 && !check(i,temp)){
      temp.push_back(i);tsum += a[st][i];wei.push_back(a[st][i]);
      find(a,n,i,en,temp,wei,fin,tsum,fsum);
      temp.pop_back();tsum -= a[st][i];wei.pop_back();
    }
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind and its weight." << endl;
  while(1){
    int x,y,w;
    cin >> x >> y >> w;
    if(x == -1 && y == -1) break;
    a[x][y] = w;
  }

  cout << "Enter the start and end vertex." << endl;
  int st,en;
  cin >> st >> en;
  vector<int> temp;vector<int> wei;
  temp.push_back(st);
  vector<int> fin;
  int tsum = 0;int fsum = INT_MAX;
  find(a,n,st,en,temp,wei,fin,tsum,fsum);

  for(int i=0;i<fin.size();i++) cout << fin[i] << " ";
  cout << endl;
  cout << "SUM : " << fsum;

  cin.get();
  cin.get();
  return 0;
}
/*0 1 2
0 3 1
1 3 3
1 4 10
3 4 2
3 6 4
3 5 8
3 2 2
4 6 6
6 5 1
2 5 5
2 0 4*/
