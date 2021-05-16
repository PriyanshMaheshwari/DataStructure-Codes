#include <bits/stdc++.h>
using namespace std;

int st(int a[],int low,int high){
  int piv = a[low];
  int l=low+1,h=high;

  while(l<=h){
    while(l<=high && a[l] < piv) l++;
    while(h>low && a[h] > piv) h--;

    if(l<=h) swap(a[l],a[h]);
  }

  swap(a[low],a[h]);
  return h;
}

void qsort(int a[],int low,int high){
  if(low > high) return;
  int j = st(a,low,high);

  qsort(a,low,j-1);
  qsort(a,j+1,high);
}

int main(){
  cout << "Enter the number elements." << endl;
  int n;cin >> n;
  int a[n];
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) cin >> a[i];
  qsort(a,0,n-1);

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;

  cin.get();cin.get();
  return 0;
}
