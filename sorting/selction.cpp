#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << "Enter the elements." << endl;
  int n;cin >> n;
  int a[n];
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) cin >> a[i];

  for(int i=0;i<n;i++){
    int min = INT_MAX,mini;
    for(int j=i;j<n-1;j++){
      if(min > a[j]){min = a[j];mini = j;}
    }
    swap(a[i],a[mini]);
  }

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;

  cin.get();cin.get();
  return 0;
}
