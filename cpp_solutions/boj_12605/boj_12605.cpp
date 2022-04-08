#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int N;
  cin >> N;
  cin.ignore();
  for (int i = 1; i <= N; i++)
  {
    string s;
    getline(cin, s);
    stringstream in(s);
    vector<string> v;
    while(in>>s)
      v.push_back(s);
    cout << "Case #" << i << ": ";
    for (int i = v.size() - 1; i >= 0;i--)
      cout << v[i] << ' ';
    cout << '\n';
  }
}