#include<iostream>
using namespace std;
struct s1;
struct s2{
    int a;
    struct s1 *b;
};

struct s1{
    struct s2 *c;
    int data;
};

int main()
{
    struct s1 *p;
    p=new(struct s1);
    p->c=new(struct s2);
    p->c->a=10;
    cout<<p->c->a;
   return 0;
}
