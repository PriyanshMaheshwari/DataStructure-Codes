#include <iostream>
#include <queue>
using namespace std;

struct X{
    int a,b,c;
};

int main()
{
    cout << "Enter the number of values" << endl;
    int n;cin >> n;
    int a[n];
    cout << "Enter the values." << endl;
    for(int i=0;i<n;i++){cin >> a[i];}

    queue<X> q;
    struct X t;
    t.a = a[0];t.b = 1;t.c = 1000;
    q.push(t);

    int i =1;
    while(i<n && q.size() != 0){
        struct X x = q.front();
        q.pop();

        if(x.a > a[i] && x.b =< a[i]){
            struct X node;
            node.a = a[i];
            node.c = x.a-1;
            node.b = x.b;
            q.push(node);
            i++;
        }
        if(i == n){break;}
        if(x.a < a[i] && x.c >= a[i]){
            struct X node;
            node.a = a[i];
            node.b = x.a+1;
            node.c = x.c;
            q.push(node);
            i++;
        }
    }

    if(i==n){cout << "Yes" << endl;}
    else{cout << "No" << endl; }

    return 0;
}
