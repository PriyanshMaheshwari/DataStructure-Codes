#include <iostream>

using namespace std;

void monthname(int year,int i){
    cout << "January," << year;
    return;
}

int printfl(int a, int cnt,int year){
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%4 == 0){days[1] = 29;}
    int temp;
    for(int i=1;i<8;i++){
        cout << "M ";
        int z;
        if(a>i){z = i-a+8 ;cout << "   " ; }
        else{z = i-a+1 ;}
        while(z <= days[cnt]){
            if(z<10){cout << z << "  " ;}
            else{cout << z << " ";}
            if(z == days[cnt]){temp = i+1;}
            z = z+7;
        }
        cout << endl;
    }
    if(temp < 8){return temp;}
    else{return temp-7 ;}
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
        a = printfl(a,i,year);
        cout << endl;
    }
    return 0;
}
