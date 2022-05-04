#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bitset<100000001> bit;

int main() {
  fastio;
  int an, bn, tmp;
  cin >> an >> bn;
  for (int i = 0; i < an + bn; i++)
  {
    cin >> tmp;
    bit[tmp].flip();
  }
  cout << bit.count() << '\n';
}