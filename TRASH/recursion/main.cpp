#include <iostream>
using namespace std;

void convert(int n,int r){
    if(n<r){cout << n ;return ;}
    else{
        convert(n/r,r);
        cout << n%r ;
    }
    return;
}

int main()
{
    char x;int n;
    cin >> x >> n;
    int r;
    switch(x){
    case 'b' :
        r = 2;break;
    case 'o':
        r = 8;break;
    case 'h':
        r = 16;break;
    }

    convert(n,r);

    return 0;
}
