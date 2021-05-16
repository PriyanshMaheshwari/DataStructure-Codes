#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,w;
};

int par(int x,vector<int> &v){
    if(v[x] < 0) return x;
    else{
        int z = par(v[x],v);
        v[x] = z;
        return z;
    }
}

void mer(int x,int y,vector<int> &v){
    v[x] = y;
}

int solve(int A, vector<vector<int>> &B) {
    vector<node> v(B.size());
    for(int i=0;i<B.size();i++){
        v[i].a = B[i][0]-1;
        v[i].b = B[i][1]-1;
        v[i].w = B[i][2];
    }
    sort(v.begin(),v.end(),[&](node &p1,node&p2){
        return p1.w < p2.w;
    });

    vector<int> p(A,-1);
    int sum = 0;
    for(int i=0;i<v.size();i++){
        int x = par(v[i].a,p);int  y = par(v[i].b,p);
        if(x!=y){
            sum += v[i].w;
            mer(x,y,p);
        }
    }

    return sum;
}
