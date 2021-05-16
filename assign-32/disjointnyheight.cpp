#include <bits/stdc++.h>
using namespace std;

void allo(int S[],int x,int &i){
  if(S[x] < 0){
    if(S[x] > i) S[x] = i;
    else return;
  }
  else allo(S,S[x],--i);
}

int sfind(int s[],int x){
  if(s[x] < 0) return x;
  return sfind(s,s[x]);
}

void uni(int S[],int x,int y){
  if(x == y) return;

  if(S[y] == 0){
    S[y] = x;
    if(S[x] == 0) { S[x] = -1; return;}
    if(S[x] < 0) return;
    else {int i=-1;allo(S,x,i);}
  }

  else if(S[x] == 0){
    S[x] = y;
    if(S[y] == 0) { S[y] = -1; return;}
    if(S[y] < 0) return;
    else {int i=-1;allo(S,y,i);}
  }

  else if(S[x] < 0 && S[y] < 0){
    if(S[x] < S[y]){
      S[y] = x;
    }
    else{
      if(S[y] == S[x]) S[y] -= 1;
      S[x] = y;
    }
  }

  else{
    int q = sfind(S,x);
    int r = sfind(S,y);
    uni(S,q,r);
  }
}

int main(){
  cout << "Enter the umber of elements." << endl;
  int n;cin >> n;
  int a[n+1];
  for(int i=0;i<=n;i++) a[i] = 0;
  cout << "Enter the keys for union." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y==-1) break;
    else uni(a,x,y);
    for(int i=0;i<n+1;i++) cout << a[i] << " ";
    cout << endl;
  }
}
