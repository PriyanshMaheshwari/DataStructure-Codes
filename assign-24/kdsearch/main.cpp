#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

union u{
    int num;
    char c;
};

struct kdnode{
    struct kdnode* lchild;
    int flag[50];
    union u data[50];
    struct kdnode* rchild;
};

typedef struct kdnode* KPTR;

KPTR getnode(string s[],int n){
  KPTR temp = new struct kdnode;
  temp->lchild = temp->rchild = NULL;
  for(int i=0;i<n;i++){
      if(s[i].size() == 1){
        if(48<=int(s[i][0]) && int(s[i][0])<=57) {
          temp->flag[i] = 0;
          temp->data[i].num = s[i][0]-'0';
        }
        else{
          temp->flag[i] = 1;
          temp->data[i].c = s[i][0];
        }
      }
      else{
        temp->flag[i] = 0;
        int j = 0;int x =0;
        while(j<s[i].size()){
          x += (s[i][j]-'0')*pow(10,s[i].size()-1-j);
          j++;
        }
        temp->data[i].num = x;
      }
  }
  return temp;
}

void add(KPTR &T,int d,int &i,string s[]){
    KPTR temp = new struct kdnode;
    temp = getnode(s,d);
    if(T == NULL){
        T = temp;
        return;
    }
    int x,y;
    if(T->flag[i%d] == 0){
        x = T->data[i%d].num;
        y = temp->data[i%d].num;
    }
    else{
        x = int(T->data[i%d].c);
        y = int(temp->data[i%d].c);
    }
    int l = i+1;
    if(x > y) add(T->lchild,d,l,s);
    else if(x < y) add(T->rchild,d,l,s);
}

void pre(KPTR T,int d){
    if(T == NULL) return;
    for(int i=0;i<d;i++){
        if(T->flag[i] == 0) cout << T->data[i].num << " " ;
        else cout << T->data[i].c << " ";
    }
    cout << endl;
    pre(T->lchild,d);
    pre(T->rchild,d);
}

int sea(KPTR T,int d,string s[],int &i){
    if(T == NULL) return 0;
    int x,y;
    if(T->flag[i%d] == 0){
        x = T->data[i%d].num;
        int j = 0;y =0;
        while(j<s[i].size()){
            y += (s[i][j]-'0')*pow(10,s[i].size()-1-j);
            j++;
        }
    }
    else{
        x = int(T->data[i%d].c);
        y = int(s[i%d][0]);
    }
    int l = i+1;
    if(x > y) return sea(T->lchild,d,s,l);
    else if(x < y) return sea(T->rchild,d,s,l);
    else{
        int j;
        for(j=0;j<d;j++){
            if(T->flag[j] == 0){
                int k = 0,z =0;
                while(k<s[j].size()){
                    z += (s[j][k]-'0')*pow(10,s[j].size()-1-k);
                    k++;
                }
                if(T->data[j].num != z) {break;}
            }
            else{
                if(T->data[j].c != s[j][0]) {break;}
            }
        }
        if(j == d) return 1;
        return 0;
    }
}

int main()
{
    KPTR T = NULL;
    cout << "Enter the no. of elements in one node." << endl;
    int d;cin >> d;
    cout << "Enter the elements of data and press -1 in all to exit." << endl;
    while(1){
        string s[d];
        for(int i=0;i<d;i++){
            cin >> s[i];
        }
        if(s[0] == "-1") break;
        int l = 0;
        add(T,d,l,s);
    }

    cout << "Enter the data you want to search." << endl;
    string s[d];
    for(int i=0;i<d;i++){
        cin >> s[i];
    }

    int l = 0;
    int x = sea(T,d,s,l);
    if(x == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
