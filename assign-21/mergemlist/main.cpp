#include <iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void perup(int H[][2],int n,int k){
    int j = n;
    while(j>0 && H[(j-1)/2][0] > k){
        int x = H[j][0],y = H[j][1];
		int a = H[(j-1)/2][0],b = H[(j-1)/2][1];
		H[j][0] = a;H[j][1] = b;
		H[(j-1)/2][0] = x;H[(j-1)/2][1] = y;
    }
}

void add(int H[][2],int n,int k,int i){
    H[n][0] = k;
    H[n][1] = i;
    perup(H,n,k);
}

void perdown(int H[][2],int n,int i){
    if(i>=n) return;
    int m = i;
    int x = 2*i+1,y = 2*i+2;
    if(x<n && H[x][0]<H[m][0]) m = x;
    if(y<n && H[y][0]<H[m][0]) m = y;
    if(m!=i){
        int x = H[m][0],y = H[m][1];
		int a = H[i][0],b = H[i][1];
		H[m][0] = a;H[m][1] = b;
		H[i][0] = x;H[i][1] = y;
        perdown(H,n,m);
    }
}

void del(int H[][2],int &n,int k){
    if(n == 0){cout << "Heap is empty." << endl;return;}
    int i = 0;
    swap(H[i],H[n-1]);
    n--;
    perdown(H,n,0);
}

int main()
{
    cout << "Enter the number of arrays." << endl;
    int n;cin >> n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        cout << "Enter the values of " << i << " list." << endl;
        vector<int> a;
        while(1){
            int x;cin >> x;
            if(x == -1) break;
            a.push_back(x);
        }
        v.push_back(a);
    }

    int H[n][2];
    H[0][0] = v[0][0];
    H[0][1] = 0;
	v[0].erase(v[0].begin());

	for(int i=1;i<n;i++){
		add(H,i,v[i][0],i);
		v[i].erase(v[i].begin());
	}

	int x = n;
	while(x != 0){
		cout << H[0][0] << " ";
		int z = H[0][1];
		del(H,x,H[0][0]);
		if(v[z].size()>0){
			add(H,x++,v[z][0],z);
			v[z].erase(v[z].begin());
		}
	}

    return 0;
}
