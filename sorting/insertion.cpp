#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a;
  cout << "Enter the elements." << endl;
  while(1){
    int x;cin >> x;
    if(x == -1) break;
    a.push_back(x);
  }

  for(int i=0;i<a.size();i++){
    int j = 0;
    while(j<i && a[j]<a[i]) j++;
    while(j!=i) {swap(a[j],a[i]);j++;}
  }

  for(int i=0;i<a.size();i++) cout << a[i] << " ";

  cin.get();cin.get();
  return 0;
}
