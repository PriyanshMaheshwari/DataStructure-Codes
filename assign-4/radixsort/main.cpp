#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(int x,struct queue &q){
    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.elements[q.r] = x;
}

int dequeue(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    int t = q.elements[q.f];
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.f = (q.f+1)%q.size;
    }
    return t;
}

int main(){
    struct queue q[10];

    for(int i=0;i<10;i++){
        q[i].size = 30;
        q[i].f = -1;
        q[i].r = -1;
    }

    int n;
    cout << "Enter the no. of elements." << endl;
    cin >> n;
    int a[n],b[n];
    cout << "Enter the elements." << endl;
    for(int i=0;i<n;i++){cin >> a[i];b[i] = a[i];}

    int max = a[0];
    for(int i=1;i<n;i++){
        if(max < a[i]){max = a[i];}
    }

    int z = 1;
    while(max>0){
        max = max/10;
        z++;
    }

    int i=0;

    while(i!=z){
        for(int i=0;i<n;i++){
            int x = b[i]%10;
            enqueue(a[i],q[x]);
        }
        int j = 0;
        for(int i=0;i<10;i++){
            while(q[i].f != -1){
                int temp = dequeue(q[i]);
                a[j] = temp;
                b[j] = temp/10;
                j++;
            }
        }
        i++;
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    return 0;
}
