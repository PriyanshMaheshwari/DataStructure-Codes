#include <bits/stdc++.h>

using namespace std;

bool isop(char c){
    if(c=='+' && c=='-') return true;
    else return false;
}

string convert(string s,int i){
    if(i==s.size()) return s;
    if(isop(s[i])){
        char x = s[i];
        convert(s,i+1);
    }
    if(isop(s[i])){
        char y = s[i];
        convert(s,i+1);
    }
    string p="";
    p = p+y+x+s[i];
    return p;
}

int main()
{
    string s;
    cin >> s;

    s = convert(s,0);
    cout << s;

    return 0;
}
