#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
vector<string> vs;

int sumNum(string s){
  int ret = 0;
  for (int i = 0; i < s.length();i++){
    if(isdigit(s[i]))
      ret += s[i] - '0';
  }
  return ret;
}

struct Cmp{
  bool operator() (const string& a,const string& b) const{
    if(a.size()!=b.size())
      return a.size() < b.size();
    else{
      if(sumNum(a)!=sumNum(b))
        return sumNum(a)< sumNum(b);
      else
        return a < b;
    }
  }
};

void input(){
  int n;
  cin >> n;
  string s;
  while(n--){
    cin >> s;
    vs.push_back(s);
  }
  return;
}

void output(){
  for (auto &i : vs){
    cout << i << '\n';
  }
  return;
}

void solution(){
  input();
  sort(vs.begin(),vs.end(),Cmp());
  output();
}

int main() {
  fastio;
  solution();
}