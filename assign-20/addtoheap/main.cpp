#include <iostream>
using namespace std;

void perup(int H[],int n,int k){
    int j = n-1;
    while(j>0 && H[(j-1)/2] > k){
        H[j] = H[(j-1)/2];
        H[(j-1)/2] = k;
        j = (j-1)/2;
    }
}

void add(int H[],int n,int k){
    H[n-1] = k;
    perup(H,n,k);
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
        H[n++] = x;
    }
    cout << "Enter the element you want to add." << endl;
    int k;cin >> k;
    ++n;
    add(H,n,k);
    for(int i=0;i<n;i++) cout << H[i] << " ";

    cin.get();cin.get();
    return 0;
}
