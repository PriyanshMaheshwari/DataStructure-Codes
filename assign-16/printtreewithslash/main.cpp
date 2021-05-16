#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
	char c;
	node *left;
	node *right;
	int x;
	int y;
} *BTPTR;
struct queu
{
	int size;
	int front;
	int rear;
	BTPTR elements[50];
};
void equeue(queu &q,BTPTR x)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		if(q.front==-1){q.front=0;}
		q.rear=(q.rear+1)%q.size;
		q.elements[q.rear]=x;
	}
}
BTPTR dqueue(queu &q)
{
	BTPTR t;
	if(q.front==-1)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		t=q.elements[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
void preorder(BTPTR T)
{
	if(T==NULL){return ;}
	cout<<T->c<<" ";
	preorder(T->left);
	preorder(T->right);
}
void inorder(BTPTR T)
{
	if(T==NULL){return ;}
	inorder(T->left);
	cout<<T->c<<" ";
	inorder(T->right);
}
void create(BTPTR &T,char s[],int n)
{
	static int i=-1;
	i++;
	if(i==n){return ;}
	if(s[i]!='.'){

		BTPTR t=new node;
		t->c=s[i];
		t->left=NULL;
		t->right=NULL;
		T=t;
		create(T->left,s,n);
		create(T->right,s,n);
	}
	else{T=NULL;return ;
		}
}
void level(BTPTR &T,int l)
{
	if(T==NULL){return ;}
	T->y=l;
	level(T->left,l+1);
	level(T->right,l+1);
}
void hor(BTPTR &T,int &m)
{
	if(T==NULL){return ;}
	hor(T->left,m);
	T->x=m;m++;
	hor(T->right,m);
}

void print(queu &q,BTPTR T,queue <char> s)
{
	if(q.front==q.rear){return ;}
	BTPTR P=dqueue(q);
	if(P==NULL)
	{	cout<<endl;
		while(!s.empty())
		{
			cout<<s.front();
			s.pop();
		}
		cout<<endl;
		equeue(q,NULL);
	}
	else
	{
		int i=0;
		if(T==NULL)
		{
		for(i=0;i<P->x-1;i++)
		{cout<<" ";s.push(' ');}
		}
		else{
			for(i=0;i<P->x-T->x-1;i++) {cout<<" ";s.push(' ');}
		}
		cout<<P->c;int f=0;
		if(P->left){s.push('/');f++;}
		if(P->right){
			if(f==0){s.push(' ');f++;}
			s.push('\\');}
		if(f==0){s.push(' ');}
		if(P->left!=NULL){equeue(q,P->left);}
		if(P->right!=NULL){equeue(q,P->right);}
	}
	print(q,P,s);
}
int main()
{
	queu q;
	queue <char> s1;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	BTPTR root=NULL;
	int n;
	cin>>n;
	char s[n];
	for(int i=0;i<n;i++) cin>>s[i];
		int i=0;
	create(root,s,n);
	cout<<endl<<"preorder:"<<endl;
	preorder(root);
	cout<<endl<<"inorder:"<<endl;
	inorder(root);
	cout<<endl;
	int k=4;
	BTPTR t1=root,t2=root;
	level(t1,1);
	hor(t2,k);
	equeue(q,root);
	equeue(q,NULL);
	cout<<"Tree:"<<endl;
	print(q,NULL,s1);
	cout<<endl;
	return 0;
}
