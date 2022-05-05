#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define LEN 2000
using namespace std;

int n, q;
bitset<LEN> mutual[LEN];

void answer(int a, int b){
  cout << (mutual[a - 1] & mutual[b - 1]).count() << '\n';
}

void input(){
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++)
  {
    cin >> mutual[i];
  }
  cin >> q;
  while(q--)
  {
    cin >> a >> b;
    answer(a, b);
  }
  return;
}

void solution(){
  input();
}

int main(){
  fastio;
  solution();
}