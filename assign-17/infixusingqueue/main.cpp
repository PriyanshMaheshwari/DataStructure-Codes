#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

union elements{
    int operand;
    char operato;
};

struct queue{
    int f;
    int r;
    int flag[50];
    union elements ele[50];
    int size;
};

void enqueueint(int x,struct queue &q){

    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.ele[q.r].operand = x;
    q.flag[q.r] = 0;
}

void enqueuechar(char x,struct queue &q){

    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.ele[q.r].operato = x;
    q.flag[q.r] = 1;
}

int dequeueint(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    int t = q.ele[q.f].operand;
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.flag[q.f] = -1;
        q.f = (q.f+1)%q.size;
    }
    return t;
}

char dequeuechar(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    char t = q.ele[q.f].operato;
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.flag[q.f] = -1;
        q.f = (q.f+1)%q.size;
    }
    return t;
}

int sol(int a,int b,char x){
    switch(x){
    case '+' :
        return a+b ;
    case '-' :
        return b-a;
    case '*' :
        return b*a;
    case '/' :
        return b/a;
    }
}

int main()
{
    struct queue q;
    q.f = -1;
    q.r = -1;
    q.size = 30;
    for(int i=0;i<q.size;i++){q.flag[i] = -1;}

    cout << "Enter the expression press $ to end." << endl;
    while(2+2 == 4){
        string s;
        cin >> s;
        if(s.size() == 1){
            if(s[0]=='$'){break;}
            if(s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/'){enqueuechar(s[0],q);}
            else{
                int x = s[0]-'0';enqueueint(x,q);
            }
        }
        else{
            int i = 0;int x =0;
            while(i<s.size()){
                x += (s[i]-'0')*pow(10,s.size()-1-i);
                i++;
            }
            enqueueint(x,q);
        }
    }
    int fl = 0;

    while(fl == 0){
        fl = 1;
        if(q.flag[q.f] == 1){enqueuechar(dequeuechar(q),q);continue;}
        else{
            int x = dequeuechar(q);
            if(q.flag[q.f] == 0){enqueueint(x,q);continue;}
            else{
                char c = dequeuechar(q);
                if(q.flag[q.f] == 1 || c == '+' || c == '-'){enqueueint(x,q);enqueuechar(c,q);continue;}
                else{
                    int y = dequeueint(q);
                    fl = 0;
                    enqueueint(sol(y,x,c),q);
                }
            }
        }
    }

    while(q.f != q.r){
        if(q.flag[q.f] == 1){enqueuechar(dequeuechar(q),q);continue;}
        else{
            int x = dequeuechar(q);
            if(q.flag[q.f] == 0){enqueueint(x,q);continue;}
            else{
                char c = dequeuechar(q);
                if(q.flag[q.f] == 1){enqueueint(x,q);enqueuechar(c,q);continue;}
                else{
                    int y = dequeueint(q);
                    enqueueint(sol(y,x,c),q);
                }
            }
        }
    }

    cout << "Answer : " << dequeueint(q) << endl;

    return 0;
}
