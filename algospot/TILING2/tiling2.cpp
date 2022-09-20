#include <iostream>
#include <memory.h>
using namespace std;

const int MOD = 1000000007;
int cache[101];
int n;

void input(){
  cin >> n;
}

int solve(int a){
  if(a <= 1)
    return 1;

  int &ret = cache[a];

  if(ret!=-1)
    return ret;

  return ret = (solve(a - 1) + solve(a - 2)) % MOD;
}

void solution(){
  int tc;
  cin >> tc;
  while (tc--)
  {
    // memset(cache, -1, sizeof(cache));
    input();
    cout << solve(n) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}