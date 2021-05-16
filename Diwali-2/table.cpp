#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << "Enter the number" << endl;
  int n;cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    a[i] = (i+1)%n;
  }
  for(int i=0;i<(n-1)/2;i++){
    for(int i=0;i<n;i++){
      cout << i << " : " << a[i] << endl;
    }
    cout << endl;
    for(int i=0;i<n;i++){
      a[i] = (a[i]+1)%n;
    }
  }

  cin.get();cin.get();
  return 0;
}
