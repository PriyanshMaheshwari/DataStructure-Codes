#include <bits/stdc++.h>
#define pb push_back
using namespace std;

union u{
  int num;
  char c;
};

int sol(int a,int b,char x){
    switch(x){
    case '+' :
        return a+b ;
    case '-' :
        return b-a;
    case '*' :
        return b*a;
    case '/' :
        return b/a;
    }
}

void primat(int **a,int n){
  cout << "  ";
  for(int i=0;i<n;i++) cout << i << " ";
  cout << endl;
  for(int i=0;i<n;i++){
    cout << i << " ";
    for(int j=0;j<n;j++) cout << a[i][j] << " ";
    cout << endl;
  }
}

int calc(int **a,int n,u w[],int f[],int l){
  if(f[l] == 1) return w[l].num;
  int x=-1,y=-1;
  for(int i=0;i<n;i++){
    if(x==-1 && a[l][i] == 1) x=i;
    else if(y==-1 && a[l][i] == 1) y=i;
  }

  return sol(calc(a,n,w,f,x),calc(a,n,w,f,y),w[l].c);
}

int main(){
  cout << "Enter the number of elements." << endl;
  int n;cin >> n;
  int **a = new int*[n];
  u w[n];
  int flag[n];
  for(int i=0;i<n;i++) a[i] = new int[n];

  cout << "Enter the keys in which you have to bind." << endl;
  while(1){
    int x,y;
    cin >> x >> y;
    if(x == -1 && y == -1) break;
    a[x][y] = 1;
  }

  cout << "Enter the weight of vertices." << endl;
  for(int i=0;i<n;i++){
    cout << "Enter weight of " << i << " with flag : " ;
    int f;cin >> f;
    if(f == -1) break;
    flag[i] = f;
    if(f == 0){char x;cin >> x;w[i].c = x;}
    else{int x;cin >> x;w[i].num = x;}
  }

  cout << "Ans : " << calc(a,n,w,flag,0);

  cin.get();
  cin.get();
  return 0;
}
/*0 1
0 3
1 3
1 4
3 4
3 6
3 5
3 2
4 6
6 5
2 5
2 0 */
