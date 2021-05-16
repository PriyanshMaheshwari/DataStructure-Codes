#include<bits/stdc++.h>
using namespace std;
struct btnode
{
  btnode *lc;
  btnode *rc;
  int data;

};
typedef btnode *BTPTR;
queue<BTPTR>q;
static int i=0,j=0;
void levelorder(int A[][10])
{
  if (q.front()==q.back())return;
  BTPTR B=q.front();
  q.pop();
  if (B==NULL){j++;q.push(NULL);}
  else
  {
    A[i][j]=B->data;
    i++;
    if (B->lc!=NULL)q.push(B->lc);
    if (B->rc!=NULL)q.push(B->rc);
  }
  levelorder(A);
}
void print(int A[][10])
{int x=0;


    for (k=0;k<=i/2;k++)
    {
      while (A[k][x]>0)
      {
        cout<<A[k][x]<<" ";
        x++:
      }
      x=0;
      if (i%2==0&&k==i/2)break;
      while(A[n-k][x]>0)
      {
        cout<<A[n-k][x]<<" ";
        x++;
      }
      x=0;
    }
  }
int main()
