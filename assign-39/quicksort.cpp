#include <bits/stdc++.h>
using namespace std;

int part(vector<int> &a,int low,int high){
  int p = a[low];
  int l = low+1;
  int h = high;
  while(l<h){
    while(l<=high && a[l] < p) l++;
    while(h>=low && a[h] > p) h--;
    if(l<h) swap(a[l],a[h]);
  }

  if(low != h) swap(a[low],a[h]);
  return h;
}

void qsort(vector<int> &a,int low,int high){
  if(low<high){
    int j = part(a,low,high);
    qsort(a,low,j-1);
    qsort(a,j+1,high);
  }
}

int main(){
  vector<int> a;
  while(1){
    int x;cin >> x;
    if(x == -1) break;
    a.push_back(x);
  }

  int low,high,p;
  low = 0;
  high = a.size()-1;
  qsort(a,low,high);

  for(int i=0;i<a.size();i++) cout << a[i] << " ";

  cin.get();cin.get();
  return 0;
}

/*36 18 12 45 63 72 10 54 60*/
