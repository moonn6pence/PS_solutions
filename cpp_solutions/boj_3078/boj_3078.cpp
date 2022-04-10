#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int main() {
  fastio;
  int n, k;
  ll ans = 0;
  queue<int> len[21];
  cin >> n >> k;
  for (int i = 0; i < n;i++){
    string name; cin >> name;
    int size = name.size();
    while(len[size].size()&&len[size].front()<i-k)
      len[size].pop();
    ans += len[size].size();
    len[size].push(i);
  }
  cout << ans;
}