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
  for(int i=0;i<n;i++) a[i] = 0;
  cout << "Enter the elements." << endl;
  while(1){
    int x;cin >> x;
    if(a[x+1] == 0 && a[x-1] == 0) a[x] = -1;
    if(a[x-1] != 0) uni(a,x,x-1);
    if(a[x+1] != 0) uni(a,x+1,x); 
  }

}
