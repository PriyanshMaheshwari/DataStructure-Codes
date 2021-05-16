#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int create(int H[],int a[],int n,int i){
  if(i>=2*n-1){
    return 0;
  }
  if(i>=n-1){
    H[i] = a[i-n+1];
  }
  else{
    H[i] = create(H,a,n,2*i+1)+create(H,a,n,2*i+2);
  }

  return H[i];
}

int main(){
  cout << "Enter the number of values." << endl;
  int n;cin >> n;
  int h=0;
  while(pow(2,h) < n) h++;
  h = pow(2,h);
  int a[h];
  cout << "Enter the values." << endl;
  int i;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  for(i;i<h;i++) a[i]=0;

  n=h;
  int H[2*n-1];
  int sum =  create(H,a,n,0);
  for(int i=0;i<2*n-1;i++) cout << H[i] << " ";

  cin.get();
  cin.get();
  return 0;
}
