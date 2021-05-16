#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int create(int H[],int a[],int n,int i){
  if(i>=2*n-1){
    return INT8_MIN;
  }
  if(i>=n-1){
    H[i] = a[i-n+1];
  }
  else{
    H[i] = max(create(H,a,n,2*i+1),create(H,a,n,2*i+2));
  }

  return H[i];
}

int range(int H[],int h,int mi,int ma,int k,int i,int j,int n){
  if(i>j) return INT8_MIN;
  if(k>=2*h-1) return INT8_MIN;

  if(i>ma || j<mi) return INT8_MIN;
  else if(i>=mi && j<=ma) {return H[k];}
  else return max(range(H,h,mi,ma,2*k+1,i,(i+j-1)/2,n),range(H,h,mi,ma,2*k+2,(i+j-1)/2+1,j,n));
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
  for(i;i<h;i++) a[i]=INT8_MIN;

  n=h;
  int H[2*n-1];
  int max =  create(H,a,n,0);
  for(int i=0;i<2*n-1;i++) if(H[i] != INT8_MIN) cout << H[i] << " ";

  int mi,ma;
  cout << "Enter the range whose min you want." << endl;
  cin >> mi >> ma;
  cout << range(H,h,mi,ma,0,1,h,n);


  cin.get();
  cin.get();
  return 0;
}
