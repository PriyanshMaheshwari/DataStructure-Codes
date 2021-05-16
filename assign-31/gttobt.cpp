#include<bits/stdc++.h>
using namespace std;
typedef struct node *btptr;
typedef struct bnode *bptr;

struct node{
	int data;
	char ch;
	btptr cptr[10];
	int cnt = 0;
};

struct bnode{
	char data;
	bptr lc = NULL,rc = NULL;
};

btptr tempGen(char key){
	btptr temp = NULL;
	temp = new(node);
	temp->ch = key;
	temp->data = 0;
	for(int i=0;i<10;i++)
	temp->cptr[i] = NULL;
	return temp;
}

bptr new_bnode(char ch){
	bptr temp = NULL;
	temp = new(bnode);
	temp->data = ch;
	temp->lc = NULL;
	temp->rc = NULL;
	return temp;
}

btptr create(btptr t,char ch[],int n,int &i){
	if(i>=n)	return NULL;
	if(ch[i++]==')')	return NULL;
	t = tempGen(ch[i-1]);
	while(1){
		t->cptr[(t->data)] = create(t->cptr[(t->data)],ch,n,i);
		if(t->cptr[t->data] == NULL)	break;
		t->data = t->data + 1;
	}
	return t;
}

void printlevel(queue<bptr> &q){
  if(q.size() == 1) return ;
  bptr t = q.front();q.pop();
  if(t == NULL){
    cout << endl;
    q.push(NULL);
    printlevel(q);
  }

  else{
  	cout << t->data << " ";
  	if(t->lc)	q.push(t->lc);
  	if(t->rc)	q.push(t->rc);
	printlevel(q);
  }
}

void in(bptr t){
	if(t==NULL)	return;
	in(t->lc);
	cout << t->data << " ";
	in(t->rc);
}

int print(btptr t,bptr &tp,btptr kh)
{
	if(t == NULL)	return 0;
	tp = new_bnode(t->ch);
	int a=0,b=0,k=0;
	for ( int i = 0 ; i < t->data ; i++ ){
		if(t->cptr[i]){

			if(k == 0){
				a = print(t->cptr[i],tp->lc,kh);
				if(a == 0){
					t->cptr[i] = NULL;
				}
			}
			if(k == 1){
				b = print(t->cptr[i],tp->rc,kh);
				if(b == 0)
				t->cptr[i] = NULL;
			}
			k++;
		}
	}
	if((k > 2) || a || b)	return 1;

	return 0;
}
int main(){
	char ch[50];
	cin.getline(ch,50);
	btptr T= NULL;
	cout << "\nSize ";
	int n;
	cin >> n;
	int k =0;
	T = create(T,ch,n,k);

	bptr temp = NULL;
	queue<bptr> q ;
	int z=1,y=0;
	while(z)
	{
		z = print(T,temp,T);
		q.push(temp);
		temp = NULL;
	}
	while(q.size()){
	cout << "\nLevel order " << q.size() << endl;
	queue<bptr> q1;
 	q1.push(q.front());q1.push(NULL);
  	cout << "\n\tLevel :  ";
  	printlevel(q1);
  	q.pop();
  }
	cin.get();cin.get();
	return 0;
	}
