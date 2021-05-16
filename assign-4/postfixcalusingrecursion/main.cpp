#include <iostream>
#include <cstring>

using namespace std;

int eval(string s,int i,int a[],int j){

    if(i==s.size()){return a[0];}

    int c = s[i];
    if(c!='+' && c!='*' && c!='-' && c!='/'){
        int x = s[i]-'0';
        a[j] = x;
        j++;
    }
    else{
        int x = a[--j];
        int y = a[--j];
        switch(s[i]){
        case '+' :
            a[j] = (x+y);break;
        case '*' :
            a[j] = (x*y);break;
        case '-' :
            a[j] = (y-x);break;
        case '/' :
            a[j] = (y/x);break;
        }
        j++;
    }

     return eval(s,i+1,a,j);
}

int main()
{
    cout << "Enter the expression." << endl;
    string s;
    cin >> s;

    int a[50];
    int ans = eval(s,0,a,0);
    cout << ans << endl;

    return 0;
}
