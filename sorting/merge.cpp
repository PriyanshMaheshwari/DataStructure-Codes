#include <bits/stdc++.h>
using namespace std;

void mer(vector<int> &a,int st,int mid,int en){
  int n1 = mid-st+1;
  int n2 = en-mid;

  int l[n1],r[n2];
  for(int i=0;i<n1;i++) l[i] = a[st+i];
  for(int i=0;i<n2;i++) r[i] = a[mid+1+i];

  int i=0,j=0,k=st;
  while(i<n1 && j < n2){
    if(l[i] < r[j]){a[k++] = l[i];i++;}
    else{a[k++] = r[j];j++;}
  }
  while(i<n1) a[k++]=l[i++];
  while(j<n2) a[k++]=r[j++];
}

void msort(vector<int> &a,int st,int en){
  if(st >= en) return;
  msort(a,st,(st+en)/2);
  msort(a,(st+en)/2+1,en);
  mer(a,st,(st+en)/2,en);
}

int main(){
  cout << "Enter the elements." << endl;
  int n;cin >> n;
  vector<int> a;
  cout << "Enter the elements" << endl;
  for(int i=0;i<n;i++) {int x;cin >> x;a.push_back(x);}

  msort(a,0,n-1);

  for(int i=0;i<n;i++) cout << a[i] << " ";
  cout << endl;
  cin.get();cin.get();
  return 0;
}
