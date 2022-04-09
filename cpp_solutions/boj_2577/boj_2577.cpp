#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int tmp,acc=1;
  vector<int> cnt(10, 0);
  for (int i = 0; i < 3; i++)
  {
    cin >> tmp;
    acc *= tmp;
  }
  string s = to_string(acc);
  for (int i = 0; i < s.size();i++) cnt[s[i] - '0']++;
  for (int i = 0; i < 10;i++) cout << cnt[i] << '\n';
}