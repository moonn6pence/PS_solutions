#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  const double pi = 3.141592;
  double d1, d2;
  cin >> d1;
  cin >> d2;
  cout << fixed;
  cout << setprecision(6);
  cout << d1 * 2 + 2 * pi * d2;
}