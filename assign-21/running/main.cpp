#include <bits/stdc++.h>
using namespace std;

void perupmax(int H[],int n,int k){
    int j = n;
    while(j>0 && H[(j-1)/2] < k){
        H[j] = H[(j-1)/2];
        H[(j-1)/2] = k;
        j = (j-1)/2;
    }
}

void perupmin(int H[],int n,int k){
    int j = n;
    while(j>0 && H[(j-1)/2] > k){
        H[j] = H[(j-1)/2];
        H[(j-1)/2] = k;
        j = (j-1)/2;
    }
}

void add(int H1[],int n,int k,int f){
    H1[n] = k;
    if(f==0)perupmax(H1,n,k);
    else perupmin(H1,n,k);
}

void perdownmax(int H[],int n,int i){
    if(i>=n) return;
    int m = i;
    int x = 2*i+1,y = 2*i+2;
    if(x<n && H[x]>H[m]) m = x;
    if(y<n && H[y]>H[m]) m = y;
    if(m!=i){
        swap(H[m],H[i]);
        perdownmax(H,n,m);
    }
}

void perdownmin(int H[],int n,int i){
    if(i>=n) return;
    int m = i;
    int x = 2*i+1,y = 2*i+2;
    if(x<n && H[x]<H[m]) m = x;
    if(y<n && H[y]<H[m]) m = y;
    if(m!=i){
        swap(H[m],H[i]);
        perdownmin(H,n,m);
    }
}

void del(int H1[],int &n,int k,int f){
    if(n == 0){cout << "Heap is empty." << endl;return;}
    int i = 0;
    while(i<n){if(H1[i] == k) break;i++;}
    swap(H1[i],H1[n-1]);
    n--;
    if(f==0) perdownmax(H1,n,i);
    else perdownmin(H1,n,i);
}

int main(){
    int H1[50];
    int H2[50];
    cout << "Enter the values and press -1 to break;." << endl;
    int n1 = 0,n2 = 0;
    cout << "Enter the elements." << endl;
    while(1){
        int x;
        cin >> x;
        if(x == -1) break;

        if(n1==0 && n2==0) add(H1,n1++,x,0);
        else if(x < H1[0]) add(H1,n1++,x,0);
        else if(x > H1[0]) add(H2,n2++,x,1);

        if(n1-n2 > 1){
            int y = H1[0];
            del(H1,n1,y,0);
            add(H2,n2++,y,1);
        }
        else if(n2-n1 > 1){
            int y = H2[0];
            del(H2,n2,y,1);
            add(H1,n1++,y,0);
        }

        int med;
        if(n1>n2) med = H1[0];
        else if(n2>n1) med = H2[0];
        else med = (H1[0]+H2[0])/2;

        cout << "Median of array : " << med << endl;
    }

    return 0;
}
