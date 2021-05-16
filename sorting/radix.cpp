#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << "Enter the elements." << endl;
  int n;cin >> n;
  int a[n];
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) cin >> a[i];

  int x = 1;
  while(x<10000){
    stack<int> h[10];
    for(int i=0;i<n;i++){
      h[(a[i]/x)%10].push(a[i]);
    }
    int j=0;
    for(int i=0;i<10;i++){
      while(!h[i].empty()) {a[j++] = h[i].top();h[i].pop();}
    }
    x *= 10;
  }

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;

  cin.get();cin.get();
  return 0;
}
