#include <bits/stdc++.h>
using namespace std;

bool compare( pair <char,int> p1,pair<char,int> p2){
  return p1.second>p2.second;
}

int main(){
  cout << "Enter the char and its freq" << endl;
  vector<pair<char,int> > v;
  while(1){
    char c;int f;
    cin >> c >> f;
    if(f == -1) break;
    pair<char,int> p;
    p = make_pair(c,f);
    v.push_back(p);
  }
  sort(v.begin(),v.end(),compare);

  pair<char,string> p[v.size()];
  string s = "";
  int i;
  for(i=0;i<v.size()-1;i++){
    p[i].first = v[i].first;
    p[i].second = s+"0";
    s = s+"1";
  }
  p[i].first = v[i].first;
  p[i].second = s;

  for(int i=0;i<v.size();i++){
    cout << p[i].first << " : " << p[i].second << endl;
  }

  cin.get();cin.get();
  return 0;
}
