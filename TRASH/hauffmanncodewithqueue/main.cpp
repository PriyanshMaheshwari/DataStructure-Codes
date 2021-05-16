#include <bits/stdc++.h>
using namespace std;

typedef struct hfnode{
    hfnode* lchild;
    int freq;
    char c;
    hfnode* rchild;
} *HTPTR;

HTPTR get(char y,int x){
    HTPTR T = new hfnode;
    T->freq = x;T->c = y;
    T->lchild = T->rchild = NULL;
    return T;
}

void decode(HTPTR T,char s, vector<int> &a){
    if(T == NULL) {return;}
    if(T->c == s){
        for(int j=0;j<a.size();j++) cout << a[j];
        return;
    }
    if(T->lchild){
        a.push_back(0);
        decode(T->lchild,s,a);
        a.pop_back();
    }
    if(T->rchild){
        a.push_back(1);
        decode(T->rchild,s,a);
        a.pop_back();
    }
}

int main()
{
    queue<HTPTR> q1,q2;
    cout << "Enter the char and its freq enter char-$ to exit." << endl;
    while(1){
        int x;char y;
        cin >> y >> x;
        if(y == '$') break;
        HTPTR temp = get(y,x);
        q1.push(temp);
    }

    while(q1.size()+q2.size() != 1){
        HTPTR temp1,temp2;
        if((!q2.empty() && !q1.empty() && q2.front()->freq < q1.front()->freq )|| q1.empty()){
            temp1 = q2.front();q2.pop();
        }
        else {
            temp1 = q1.front();q1.pop();
        }
        if((!q2.empty() && !q1.empty() && q2.front()->freq < q1.front()->freq) || q1.empty()){
            temp2 = q2.front();q2.pop();
        }
        else {
            temp2 = q1.front();q1.pop();
        }
        HTPTR temp3 = new hfnode;
        temp3->c = '#';temp3->freq = temp1->freq + temp2->freq;
        temp3->lchild = temp1;
        temp3->rchild = temp2;

        q2.push(temp3);
    }

    HTPTR T = q2.front();q2.pop();


    cout << "Enter the string to encode." << endl;
    string s;cin >> s;
    cout << "Encoded : " ;
    for(int i=0;i<s.size();i++){
        vector<int> a;
        decode(T,s[i],a);
    }

    return 0;
}
