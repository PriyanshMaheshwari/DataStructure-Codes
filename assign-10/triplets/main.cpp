#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct dlnode;
typedef dlnode *DPTR;

struct dlnode{
    DPTR left;
    int data;
    DPTR right;
};

void addbegin(int x,DPTR &head){
    DPTR T = new dlnode;
    T->data = x;
    T->left = NULL;
    T->right = head;
    head = T;
}

void add(int x,DPTR &head){
    DPTR T1 = new dlnode;
    T1 = head;
    if(T1 == NULL){addbegin(x,head);return;}
    while(T1->right != NULL){T1 = T1->right;}
    DPTR T = new dlnode;
    T->data = x;
    T->right = NULL;
    T->left = T1;
    T1->right = T;
}

void printdl(DPTR head){
    if(head == NULL){return;}
    cout << head->data << " ";
    printdl(head->right);
}

void deletebegin(DPTR &head){
    DPTR T = head;
    head = T->right;
    T->right->left = NULL;
    delete(T);
}

void deleteend(DPTR &head){
    DPTR T = head;
    if(T->right == NULL){deletebegin(head);}
    while(T->right != NULL){T = T->right;}
    T->left->right = NULL;
    T->left = NULL;
    delete(T);
}

void del(int x,DPTR &head){
    DPTR T = head;
    if(head->data == x){deletebegin(head);return;}
    while(T->data != x){T = T->right;}
    if(T->right == NULL){deleteend(head);return;}
    T->left->right = T->right;
    T->right->left = T->left;
    delete(T);
}

int cnt(DPTR head){
    int i=0;
    while(head != NULL){i++;head = head->right;}
    return i;
}

int main()
{
    DPTR head = NULL;
    cout << "Enter the DLL and press -1 to end." << endl;
    while(1){
        int x;cin >>x;
        if(x==-1){break;}
        add(x,head);
    }
    cout << "Enter the value." << endl;
    int n;cin >> n;

    vector<vector<int> > res;
    vector<int> a;
    DPTR T = head;
    while(T->right!=NULL){T = T->right;}

    DPTR I = head;
    int i=0;
    while(I!=NULL){
        DPTR J = I->right;int j =i+1;
        DPTR K = T;int k = cnt(head);
        while(i<j && j<k){
            if(i==j){J = J->right;j++;continue ;}
            else if(i==k){K = K->left;k--;continue;}
            else{
                int x = I->data + J->data + K->data;
                if(x<n){J = J->right;j++;}
                else if(x>n){K = K->left;k--;}
                else{
                    a.push_back(I->data);
                    a.push_back(J->data);
                    a.push_back(K->data);
                    res.push_back(a);
                    a.clear();
                    if(J->data == J->right->data){J = J->right;j++;}
                    else{K = K->left;k--;}
                }
            }
        }
        I = I->right;
        i++;
    }

    for(int i=0;i<res.size();i++){sort(res[i].begin(),res[i].end()) ;}

    sort(res.begin(),res.end());

    i=0;
    while(i<res.size()){
        int j = i;
        while(res[j] == res[i]){j++;}
        if(j>i+1){res.erase(res.begin()+1+i,res.begin()+j);}
        i++;
    }

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " " ;
        }
        cout << endl;
    }

    return 0;
}
