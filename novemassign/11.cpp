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

void pridfs(int **a,vector<int> &temp,vector<vector<int>> &res,int n,int k,int en){
  if(k == en) {res.pb(temp);return;}
  for(int i=0;i<n;i++){
    if(a[k][i] > 0 && !check(i,temp)){
      temp.pb(k);
      pridfs(a,temp,res,n,i,en);
      temp.pop_back();
    }
  }
}

bool rela(string s1,string s2){
  int x = s1.size()-s2.size();
  if(x>1 || x<-1) {return false;}
  if(s1 == s2) return true;

  if(s1.size() == s2.size()){
    int cnt = -1;
    for(int i=0;i<s1.size();i++){
      if(s1[i] != s2[i]){
        if(cnt == -1) cnt = i;
        else return false;
      }
    }
    return true;
  }

  if(s1.size() > s2.size()){
    for(int i=0;i<s1.size();i++){
      string s = s1;s.erase(s.begin()+i);
      if(s == s2) return true;
    }
    return false;
  }

  if(s1.size() < s2.size()){
    for(int i=0;i<s2.size();i++){
      string s = s2;s.erase(s.begin()+i);
      if(s == s1) return true;
    }
    return false;
  }
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  for(int i=0;i<n;i++) a[i] = new int[n];
  string wei[n];

  cout << "Enter the string of each in which you have to bind." << endl;
  for(int i=0;i<n;i++) cin >> wei[i];

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(rela(wei[i],wei[j])) a[i][j] = a[j][i] = 1;
    }
  }

  primat(a,n);
  cout << endl;
  cout << "Enter the intial anf final word you need." << endl;
  string s1,s2;cin >> s1 >> s2;
  int st,en;
  for(int i=0;i<n;i++){
    if(wei[i] == s1) st=i;
    if(wei[i] == s2) en=i;
  }

  vector<int> temp;
  vector<vector<int>> res;
  pridfs(a,temp,res,n,st,en);

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++) cout << wei[res[i][j]] << " ";
    cout << wei[en];
    cout << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
