#include <iostream>
#include <memory.h>

using namespace std;

int n;
int seq[500];
int cache[501];

void input(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> seq[i];
  }
}

int solve(int start){
  int& ret = cache[start + 1];
  if(ret != -1)
    return ret;
  ret = 1;
  for (int next = start + 1; next < n; next++)
  {
    if(start == -1 || seq[start] < seq[next]){
      ret = max(ret, solve(next) + 1);
    }
  }
  return ret;
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    memset(cache, -1, sizeof(cache));
    input();
    cout << solve(-1) - 1 << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solution();
}