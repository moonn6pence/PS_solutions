#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  set<string> str_set;
  for (int i = 0; i < s.size();i++){
    for (int j = 1; j < s.size()-i+1;j++){
      str_set.insert(s.substr(i, j));
    }
  }
  cout << str_set.size() << '\n';
}