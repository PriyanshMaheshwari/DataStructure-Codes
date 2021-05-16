#include <iostream>
using namespace std;

struct node;
typedef struct node* NPTR;
union st{
	int S;
	NPTR course;
};
union cou{
	char C;
	NPTR student;
};
struct node{
	int flag1;
	int flag2;
	union st snext;
	union cou cnext;
};

void add(NPTR &stud,NPTR &cours){
    NPTR n = new struct node;
    n->flag1 = 1;
    n->flag2 = 1;
    n->cnext.student = NULL;
    n->snext.course = NULL;
    NPTR t1 = stud;
    NPTR t2 = cours;
    while(t1->cnext.student != NULL){t1 = t1->cnext.student;}
    while(t2->snext.course != NULL){t2 = t2->snext.course;}
    t1->cnext.student = n;
    t2->snext.course = n;
}

void finalisestudent(NPTR &stud){
    NPTR t1 = stud;
    while(t1->cnext.student != NULL){t1 = t1->cnext.student;}
    t1->cnext.student = stud;
}

void finalisecourse(NPTR &cours){
    NPTR t2 = cours;
    while(t2->snext.course != NULL){t2 = t2->snext.course;}
    t2->snext.course = cours;
}

void printcourse(NPTR &cours){
    NPTR T = cours;
    T = T->snext.course;
    while(T->flag2 != 0){
        NPTR temp = T;
        while(temp->flag1!=0){temp = temp->cnext.student;}
        cout << temp->snext.S << " ";

        T = T->snext.course;
    }
    cout << endl;
}

void printstudent(NPTR &stud){
    NPTR T = stud;
    T = T->cnext.student;
    while(T->flag1!=0){
        NPTR temp = T;
        while(temp->flag2!=0){temp = temp->snext.course;}
        cout << temp->cnext.C << " ";

        T = T->cnext.student;
    }
    cout << endl;
}

int main(){

cout << "Enter the no. of students." << endl;
int n1;
cin >> n1;
NPTR stud[n1];
for(int i=0;i<n1;i++){

    stud[i] = new struct node;
	stud[i]->flag1 = 0;
	cout << "Enter the roll no. of student." << endl;
	int x;cin >> x;
	stud[i]->snext.S = x;
	stud[i]->flag2 = 1;
	stud[i]->cnext.student  =NULL;
}

cout << "Enter the no. of courses." << endl;
int n2;
cin >> n2;
NPTR cours[n2];
for(int i=0;i<n2;i++){
    cours[i] = new struct node;
	cours[i]->flag2 = 0;
	cout << "Enter the subject." << endl;
	char x;cin >> x;
	cours[i]->cnext.C = x;
	cours[i]->flag1 = 1;
	cours[i]->snext.course = NULL;
}

cout << "Enter the subject and course number. Press -1 and z to exit." << endl;
while(1){
    int x;
    char y;
    cin >> x >> y;
    if(x == -1 && y == 'z'){break;}
    int p,q;
    for(int i=0;i<n1;i++){
            if(x==stud[i]->snext.S){p = i;break;}
    }
    for(int i=0;i<n1;i++){
            if(y==cours[i]->cnext.C){q = i;break;}
    }
    add(stud[p],cours[q]);
}

for(int i=0;i<n1;i++){finalisestudent(stud[i]);}
for(int i=0;i<n2;i++){finalisecourse(cours[i]);}

while(1){
    cout << "Enter 1 to find course of student or 2 for vice-versa or 0 to end." << endl;
    int a;cin >> a;
    if(a == 0){break;}
    if(a == 1){
        cout << "Enter the no. of student." << endl;
        int x;cin >> x;
        int p;
        for(int i=0;i<n1;i++){
            if(x==stud[i]->snext.S){p = i;break;}
        }
        printstudent(stud[p]);
    }
    else{
        cout << "Enter the no. of course." << endl;
        char x;cin >> x;
        int p;
        for(int i=0;i<n1;i++){
            if(x==cours[i]->cnext.C){p = i;break;}
        }
        printcourse(cours[p]);
    }
}

return 0;
}
