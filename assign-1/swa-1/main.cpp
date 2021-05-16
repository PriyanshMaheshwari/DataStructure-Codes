#include <iostream>

using namespace std;

void swa(int x,int *y){
    int *t = y;
    *y = x;
    int* p = &x;
    *p = *t;
}

int main()
{
    int a = 3,b=5;
    swa(a,&b);
    cout << a << b;
    return 0;
}
