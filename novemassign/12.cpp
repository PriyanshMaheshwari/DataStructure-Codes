#include <bits/stdc++.h>
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


int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int a[n];
  for(int i=0;i<n;i++) a[i] = -1;

  cout << "Enter the matrix." << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int x;cin >> x;
      if(x == 1 && sfind(a,i)!=sfind(a,j)){uni(a,i,j);}
    }
  }

  int cnt = 0;
  for(int i=0;i<n;i++) if(a[i] < 0)cnt++;
  cout << "No. of circle : " << cnt << endl;

  cin.get();cin.get();
  return 0;
}
