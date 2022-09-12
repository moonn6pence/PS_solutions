#include <iostream>
#include <memory.h>

using namespace std;
typedef long long ll;

ll n, m;
ll A[101], B[101];
int cache[101][101];

void input(){
  cin >> n >> m;

  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  for (int i = 0; i < m; i++){
    cin >> B[i];
  }
}

int solve(int indexA,int indexB){
  int &ret = cache[indexA + 1][indexB + 1];

  if(ret != -1)
    return ret;

  ret = 2;

  ll a = indexA == -1 ? -2e16 : A[indexA];
  ll b = indexB == -1 ? -2e16 : B[indexB];

  ll maxElement = max(a, b);

  for (int nextA = indexA + 1; nextA < n; nextA++){
    if(maxElement < A[nextA])
      ret = max(ret, solve(nextA, indexB) + 1);
  }

  for (int nextB = indexB + 1; nextB < m; nextB++){
    if(maxElement < B[nextB])
      ret = max(ret, solve(indexA, nextB) + 1);
  }

  return ret;
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    memset(cache, -1, sizeof(cache));
    input();
    cout << solve(-1, -1) - 2 << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}