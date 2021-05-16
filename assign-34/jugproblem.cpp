#include <iostream>
#include <vector>
using namespace std;

struct state{
  int a;
  int b;
};

bool check(vector<state> temp,int x,int y){
  for(int i=0;i<temp.size();i++)if(temp[i].a == x && temp[i].b == y) return false;
  return true;
}

void jugpro(vector<vector<state > > &res,vector<state> &temp,state pre,state tot,int k){
  int x = pre.a,y = pre.b;
  if(pre.a == k || pre.b == k){
    temp.push_back(pre);
    res.push_back(temp);
    temp.pop_back();
    return;
  }

  temp.push_back(pre);
  if(x!=0 && check(temp,0,y)){
    state s;s.a = 0;s.b = y;
    jugpro(res,temp,s,tot,k);
  }
  if(y!=0 && check(temp,x,0)){
    state s;s.a = x;s.b = 0;
    jugpro(res,temp,s,tot,k);
  }
  if(x!=tot.a && check(temp,tot.a,y)){
    state s;s.a = tot.a;s.b = y;
    jugpro(res,temp,s,tot,k);
  }
  if(y!=tot.b && check(temp,x,tot.b)){
    state s;s.a = x;s.b = tot.b;
    jugpro(res,temp,s,tot,k);
  }

  int l = min(x,tot.b-y);
  if(y!=tot.b && check(temp,x-l,y+l)){
    state s;s.a = x-l;s.b = y+l;
    jugpro(res,temp,s,tot,k);
  }

  l = min(y,tot.a-x);
  if(x!=tot.a && check(temp,x+l,y-l)){
    state s;s.a = x+l;s.b = y-l;
    jugpro(res,temp,s,tot,k);
  }
  temp.pop_back();

}

int main(){
  struct state tot;
  cout << "Enter the capacity of judges." << endl;
  cin >> tot.a >> tot.b;
  cout << "Enter the amount you want to be final in present." << endl;
  int k;cin >> k;
  struct state prese;
  prese.a = 0;prese.b = 0;
  vector<state> ans;
  vector<vector<state > > res;
  jugpro(res,ans,prese,tot,k);

  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++) cout << "(" << res[i][j].a << "," << res[i][j].b << ")" << " ";
    cout << endl;
  }

  cin.get();cin.get();
  return 0;
}
