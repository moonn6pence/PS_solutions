#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  vector<int> cnt(26, 0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size();i++) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26;i++) cout << cnt[i] << ' ';
  cout << '\n';
}