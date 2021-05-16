#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    char elements[50];
};

void enqueue(char x,struct queue &q){
    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.elements[q.r] = x;
}

char dequeue(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    int t = q.elements[q.f];
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.f = (q.f+1)%q.size;
    }
    return t;
}

void check(struct queue &q,int s,int &ans){
    if(s<2){return;}

    char c = dequeue(q);
    for(int i=0;i<s-2;i++){enqueue(dequeue(q),q);}
    char x = dequeue(q);
    if(x == c){check(q,s-2,ans); }
    else{ans = 0;return;}

}

int main()
{
    struct queue q;
    q.size = 30;
    q.f = -1;q.r = -1;

    cout << "Enter the string and enter 0 to end." << endl;
    int size=0;
    while(2+2==4){
        char c;
        cin >> c;
        if(c=='0'){break;}
        else{enqueue(c,q);size++;}
    }

   /*while(q.f != -1 && size>1){
        char c = dequeue(q);
        for(int i=0;i<size-2;i++){enqueue(dequeue(q),q);}
        char x = dequeue(q);
        if(x == c){size = size-2;}
        else{cout << "NO" << endl; break;}
    }

    if(size <=1){cout << "YES";}*/

    int ans = 1;
    check(q,size,ans);
    if(ans == 0){cout << "NO" << endl;}
    else{cout << "YES" << endl;}

    return 0;
}
