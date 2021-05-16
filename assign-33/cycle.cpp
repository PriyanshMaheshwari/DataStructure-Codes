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
    if(a==b) {cout << "Cycle is present." << endl;return;}
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

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int a[n];
  for(int i=0;i<n;i++) a[i] = -1;
  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x==-1 && y == -1) break;
    else uni(a,x,y);
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
  }

}
