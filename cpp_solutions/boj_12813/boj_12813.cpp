#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  string tmp;
  bitset<100000> a, b;
  cin >> a >> b;
  cout << (a & b) << '\n';
  cout << (a | b) << '\n';
  cout << (a ^ b) << '\n';
  cout << (~a) << '\n';
  cout << (~b) << '\n';
}