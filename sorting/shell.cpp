#include <bits/stdc++.h>
using namespace std;

void ssort(int a[],int n){
  for(int gap = n/2;gap>0;gap = gap/2){
    for(int i=gap;i<n;i++){
      for(int j = i;j-gap>=0;j -= gap){
        if(a[j] < a[j-gap]) swap(a[j],a[j-gap]);
      }
    }
  }
}

int main(){
  cout << "Enter the elements." << endl;
  int n;cin >> n;
  int a[n];
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) cin >> a[i];

  ssort(a,n);

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;
  cin.get();cin.get();
  return 0;
}
