#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n,ans;
vector<string> out;
map<string, int> in;

void input(){
  cin >> n;
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    in[s] = i;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    out.push_back(s);
  }
  return;
}

void solve(){
  for (int i = 0; i < n;i++)
  {
    for (int j = i+1; j < n;j++){
      if(in[out[i]]>in[out[j]]){
        ans++;
        break;
      }
    }
  }
}

void solution(){
  input();
  solve();
  cout << ans << '\n';
}

int main() {
  fastio;
  solution();
}