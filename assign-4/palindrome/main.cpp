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

int main()
{
    struct queue q1;
    q1.size = 30;
    q1.f = -1;q1.r = -1;
    struct queue q2;
    q2.size = 30;
    q2.f = -1;q2.r = -1;

    cout << "Enter the string and enter 0 to end." << endl;
    int size=0;
    while(2+2==4){
        char c;
        cin >> c;
        if(c=='0'){break;}
        else{enqueue(c,q1);size++;}
    }

    int mid;
    if(size%2 == 0){
            mid = (size/2)-1;
            int i = 0;
            while(i<=mid){
                enqueue(dequeue(q1),q2);
                i++;
            }
    }
    else{
        mid = (size/2)-1;
        int i = 0;
        while(i<=mid){
            enqueue(dequeue(q1),q2);
            i++;
        }
        char c = dequeue(q1);
    }

    int i=0;
    while(i<=mid){
        enqueue(dequeue(q2),q2);
        i++;
    }

    int flag = 0;

    while(q1.f != -1){
        if(dequeue(q2) == dequeue(q1)){continue;}
        else{cout << "NO" << endl;flag = 1;break;}
    }

    if(flag == 0){cout << "YES" << endl;}

    return 0;
}
