#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;cin >> T;
    for(int l=0;l<T;l++){
        int c,n,m;
        cin >> n >> c >> m;
        int sum = 0,wrap = 0;
        while(n>=c){
            int x =  n/c;
            sum += x;
            wrap += x;
            //cout << n%c << " " << wrap/m << endl;
            n = n%c+(c*(wrap/m));
            //cout << n << endl;
            wrap = wrap%m;
            cout << wrap << endl;
        }

        cout << sum << endl;
    }
    cin.get();cin.get();
    return 0;
}
