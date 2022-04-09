#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int n; cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n;i++) cin >> num[i];
  int v,cnt=0;
  cin >> v;

  for (int i = 0; i < n;i++){
    if(num[i]==v) cnt++;
  }
  cout << cnt;
}