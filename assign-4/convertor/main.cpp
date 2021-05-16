#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;int f2;
    int r;int r2;
    int elements[50];
    char radix[50];

};

void enqueue(int x,char c,struct queue &q){
    if((q.r+1)%q.size == q.f){cout << "Queue is full." << endl;return;}

    if(q.f == -1){q.f = 0;q.r = 0;}
    else{
        q.r = (q.r+1)%q.size ;
    }
    q.elements[q.r] = x;
    q.radix[q.r] = c;
    q.f2 = q.f;
    q.r2 = q.r;
}

int dequeueint(struct queue &q){
    if(q.f == -1){cout << "Queue is empty." << endl;return -1;}

    int t = q.elements[q.f];
    if(q.f == q.r){q.f = -1;q.r = -1;}
    else{
        q.f = (q.f+1)%q.size;
    }
    return t;
}

char dequeuechar(struct queue &q){
    if(q.f2 == -1){cout << "Queue is empty." << endl;return 'x';}

    char t = q.radix[q.f2];
    if(q.f2 == q.r2){q.f2 = -1;q.r2 = -1;}
    else{
        q.f2 = (q.f2+1)%q.size;
    }
    return t;
}

void convert(int a,char r){
    switch(r){

    case 'b' :
        {

        int n = a;
        int i;
        int ar[100];
        for(i=0; n>0; i++){
            ar[i]=n%2;
            n= n/2;
        }
        for(i=i-1 ;i>=0 ;i--){
            cout<<ar[i];
        }
        break;
        }

    case 'x' :
        {
        char hexdec[100];
        int n1 = a,temp;
        int i=1;
        while(n1!=0){
		temp=n1%16;
		if(temp<10){
			temp=temp+48;
		}
		else{
			temp=temp+55;
		}
		hexdec[i++]=temp;
		n1=n1/16;
        }
        for(int j=i-1; j>0; j--){
		cout<<hexdec[j];
        }
        break;
        }

    case 'o' :
        {
        int octnum[100];
        int n2 = a;
        int i=1;
        while(n2!=0){
		octnum[i++]=n2%8;
		n2=n2/8;
        }
        for(int j=i-1; j>0; j--){
		cout<<octnum[j];
        }
        break;
        }

    case 'p' :
        {
        int num = 0;
        int z = a,i=0;
        int v[100];
        while(z>0){
            v[i] = z%10;
            z = z/10;
            i++;
        }
        i--;
        while(i>=0){
            switch(v[i]){
                case 1: cout<<"one ";
                break;
                case 2: cout<<"two ";
                break;
                case 3: cout<<"three ";
                break;
                case 4: cout<<"four ";
                break;
                case 5: cout<<"five ";
                break;
                case 6: cout<<"six ";
                break;
                case 7: cout<<"seven ";
                break;
                case 8: cout<<"eight ";
                break;
                case 9: cout<<"nine ";
                break;
            }
            i--;
        }
        }
    }


}

int main(){
    struct queue q;
    q.size = 30;
    q.f = -1;q.r = -1;

    cout << "Give the entries and type 0 0 to end." << endl;
    while(2+2 == 4){
        int x;char c;
        cin >> x >> c;
        if(x == 0 && c == '0'){break;}
        else{enqueue(x,c,q);}
    }

    while(q.f != -1){
        convert(dequeueint(q),dequeuechar(q));
        cout << endl;

    }

    return 0;
}
