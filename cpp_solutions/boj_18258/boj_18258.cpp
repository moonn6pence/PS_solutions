#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  queue<int> Q;
  int n,num;
  string inst;
  cin >> n;
  while (n--)
  {
    cin >> inst;
    if(inst=="push"){
      cin >> num;
      Q.push(num);
    }else if(inst=="pop"){
      cout << (Q.empty()?-1:Q.front())<<'\n';
      Q.empty() ? void():Q.pop();
    }else if(inst=="size"){
      cout << Q.size()<<'\n';
    }else if(inst=="empty"){
      cout << Q.empty()<<'\n';
    }else if(inst=="front"){
      cout << (Q.empty()?-1:Q.front())<<'\n';
    }else if(inst=="back"){
      cout << (Q.empty()?-1:Q.back())<<'\n';
    }
  }
}