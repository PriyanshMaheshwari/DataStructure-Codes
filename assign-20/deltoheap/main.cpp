#include <bits/stdc++.h>
using namespace std;

void perup(int H[],int n,int k){
    int j = n;
    while(j>=0 && H[(j-1)/2] > k){
        H[j] = H[(j-1)/2];
        H[(j-1)/2] = k;
        j = (j-1)/2;
    }
}

void add(int H[],int n,int k){
    H[n] = k;
    perup(H,n,k);
}

void perdown(int H[],int n,int i){
    if(i>=n) return;
    int m = i;
    int x = 2*i+1,y = 2*i+2;
    if(x<n && H[x]<H[m]) m = x;
    if(y<n && H[y]<H[m]) m = y;
    if(m!=i){
        swap(H[m],H[i]);
        perdown(H,n,m);
    }
}

void del(int H[],int &n,int k){
    if(n == 0){cout << "Heap is empty." << endl;return;}
    int i = 0;
    while(i<n){if(H[i] == k) break;i++;}
    swap(H[i],H[n-1]);
    n--;
    perdown(H,n,i);
}

int main()
{
    int H[50];
    cout << "Enter the values of heap and press -1 to break;." << endl;
    int n = 0;
    cout << "Enter the elements." << endl;
    while(1){
        int x;
        cin >> x;
        if(x == -1) break;
        add(H,n++,x);
    }
    int temp = n;
    for(int i=0;i<temp;i++){
        cout << H[0] << " ";
        del(H,n,H[0]);
    }

    return 0;
}
