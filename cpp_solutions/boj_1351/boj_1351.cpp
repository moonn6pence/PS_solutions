#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;
map<ll, ll> A;
ll n,p,q;

void input(){
  cin >> n >> p >> q;
}

ll dp(ll n){
  ll &ret = A[n];
  if(n==0) return 1;
  if(ret!=0)
    return ret;
  return ret = dp(n/p)+dp(n/q);
}

void solve(){
  input();
  cout << dp(n) << '\n';
}

int main() {
  fastio;
  solve();
}