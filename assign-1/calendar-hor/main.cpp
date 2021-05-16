#include <iostream>
using namespace std;

void monthname(int year,int i){
    cout << "January," << year;
    return;
}

void print(){
    cout << "M  T  W  T  F  S  S" << endl;
    return;
}

int printfl(int a, int cnt,int year){
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%4 == 0){days[1] = 29;}
    int i,z=1;
    for(i=1;i<a;i++){cout << "   " ;}
    for(i;i<8;i++){cout << z << "  ";z++;}
    cout << endl;
    i=1;
    while(z<=days[cnt]){
        if(z<10){cout << z << "  " ;}
        else{cout << z << " ";}
        if(i%7 == 0){cout << endl;i=0;}
        z++;i++;
    }
    return i;
}

int main()
{
    cout << "Enter the year." << endl;
    int year;
    cin >> year;
    cout << "Enter day of first date." << endl;
    int a;
    cin >> a;

    for(int i=0;i<12;i++){
        monthname(year,i);
        cout << endl;
        print();
        a = printfl(a,i,year);
        cout << endl;
    }

    cin.get();cin.get();
    return 0;
}
