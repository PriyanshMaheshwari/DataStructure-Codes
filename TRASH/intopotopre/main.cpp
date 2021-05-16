#include <bits/stdc++.h>
using namespace std;

string convert(string s,int i,stack<string> &S){
    if(i<0) {return S.top();}
    string c = "";
    c += s[i];
    if(c[0]!='+' && c[0]!='-' && c[0]!='*' && c[0]!='/') { S.push(c);}
    else{
        string a = S.top();S.pop();
        string b = S.top();S.pop();
        c = '('+a+c+b+')';
        S.push(c);
    }
    return convert(s,i-1,S);
}

int main()
{
    cout << "Enter the expression." << endl;
    string s;
    cin >> s;
    stack<string> S;

    /*for(int i=s.size()-1;i>=0;i--){
        string c = "";
        c += s[i];
        if(c[0]!='+' && c[0]!='-' && c[0]!='*' && c[0]!='/') S.push(c);
        else{
            string a = S.top();S.pop();
            string b = S.top();S.pop();
            c = '('+a+c+b+')';
            S.push(c);
        }
    }

    cout << S.top() << endl;*/
    string x = convert(s,s.size()-1,S);
    cout << x;

    /*for(int i=s.size()-1;i>=0;i--){
        string c = "";
        c += s[i];
        if(c[0]!='+' && c[0]!='-' && c[0]!='*' && c[0]!='/') S.push(c);
        else{
            string a = S.top();S.pop();
            string b = S.top();S.pop();
            c = a+b+c;
            S.push(c);
        }
    }

    cout << S.top() << endl;*/

    return 0;
}
