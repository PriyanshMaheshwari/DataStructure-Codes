#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;cin >> T;
  for(int l=0;l<T;l++){
    int n;cin >> n;
    int v[n];
    int x = 2;
    for(int i=0;i<n;i++) v[i] = INT_MIN;
    int i;
    for( i=1;i<=n;i++){
      if(v[x%n]==INT_MIN) v[x%n] = i;
      else break;
      x += 2+i;
    }

    if(i==n+1) {cout << -1 << endl;continue;}
    else{
      for(int i=0;i<n;i++) cout << v[i] << " ";
    }
  }

  return 0;
}
