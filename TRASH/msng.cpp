#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int conv(int n,string r){
  int sum = 0,i=r.size()-1;
  while(i>=0){
    char x = r[i];
    int y;
    if(47 < int(x) && int(x) < 58) {
      y = x-'0';
    }
    else{
      y = int(x);
      y -= 55;
    }

    if(y>=n) return -1;
    else sum+= y*pow(n,r.size()-1-i);
    i--;
  }
  return sum;
}

int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;cin >> T;
    for(int l=0;l<T;l++){
        int n;cin >> n;
        int a[n];
        string b[n];
        for(int i=0;i<n;i++) cin >> a[i] >> b[i];
        vector<int> com;
        for(int i=0;i<n;i++){
          vector<int> v;
          if(a[i]==-1){
            for(int j=2;j<=36;j++){
              int x = conv(j,b[i]);
              if(x!=-1)v.push_back(x);
            }
          }
          else{
            int x = conv(a[i],b[i]);
            v.push_back(x);
          }
          if(i==0) com = v;
          else{
            int k;
            for(int j=0;j<com.size();j++){
              for(k = 0;k<v.size();k++){
                if(com[j]==v[k])break;
                else if(com[j]<v[k]){
                  com.erase(com.begin()+j);
                  j--;
                  break;
                }
              }
            }
          }
        }

        if(com.size()==0) cout << -1 << endl;
        else cout << com[0] << endl;
    }
	return 0;
}
