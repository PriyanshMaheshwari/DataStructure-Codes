#include <bits/stdc++.h>
using namespace std;

int seg[500000];
void build(vector<int> &a,int no,int st,int en){
  if(st == en){
    seg[no] = a[st];return;
  }
  int mid = (st+en)/2;
  build(a,2*no+1,st,mid);
  build(a,2*no+2,mid+1,en);
  seg[no] = seg[2*no+1]+seg[2*no+2];
}

int query(int no,int st,int en,int l,int r){
  if(st >r || en < l) return 0;
  if(st>=l&&en<=r) return seg[no];
  int mid = (st+en)/2;
  return query(2*no+1,st,mid,l,r) + query(2*no+2,mid+1,en,l,r);
}

void update(int no,int st,int en,int ind,int val){
  if(st == en){
    seg[no] = val;return;
  }
  int mid = (st+en)/2;
  if(ind <= mid) update(2*no+1,st,mid,ind,val);
  else update(2*no+2,mid+1,en,ind,val);

  seg[no] = seg[2*no+1]+seg[2*no+2];
}

int main(){
  int n;cin >> n;
  vector<int> a;
  for(int i=0;i<n;i++) cin >> a[i];
}
