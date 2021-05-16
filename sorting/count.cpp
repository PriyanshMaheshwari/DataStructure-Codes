#include <bits/stdc++.h>
using namespace std;

void csort(int a[],int n){
  map<int,int> m;
  for(int i=0;i<n;i++) m[a[i]]++;
  int x=0;
  int cnt[10];
  for(int i=0;i<10;i++) { cnt[i]=(x+m[i]);x+=m[i];}
  for(int i=0;i<10;i++) cout << cnt[i] << " ";
  cout << endl;
  x=0;
  for(int i=0;i<10;i++){
    int h=0;
    while(cnt[i]-x > 0) {a[cnt[i]-1]=i;h++;cnt[i]--;}
    x+=h;
  }
}

int main(){
  cout << "Enter the number elements." << endl;
  int n;cin >> n;
  int a[n];
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) cin >> a[i];

  csort(a,n);

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;

  cin.get();cin.get();
  return 0;
}
