#include <iostream>

using namespace std;

void func(int a[],int n,int t,double& avg,int& mi,int& ma){
    static double av = 0;
    static int max = a[n];
    static int min = a[n];
    av += a[n]/(1.0 * t) ;
    if(max < a[n]){max = a[n];}
    if(min > a[n]){min = a[n];}
    if(n==0){avg = av;mi = min;ma = max;return;}
    func(a,n-1,t,avg,mi,ma);
}

int main()
{
    cout << "Enter the size of array." << endl;
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements of array." << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    double avg = 0;
    int min = 0;
    int max = 0;
    func(a,n-1,n,avg,min,max);

    cout << avg << " " << min << " " << max ;

    return 0;
}
