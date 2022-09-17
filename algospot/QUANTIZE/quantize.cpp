#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, s;
int A[101], pSum[101], pSqSum[101], cache[101][11];

void calcPartial(){
  sort(A, A + n);
  pSum[0] = A[0];
  pSqSum[0] = A[0] * A[0];
  for (int i = 1; i < n; i++) {
    pSum[i] = pSum[i - 1] + A[i];
    pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
  }
}

void input(){
  cin >> n >> s;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
}

int minError(int a, int b) {
  int sum = pSum[b] - (a == 0 ? 0 : pSum[a - 1]);
  int sqSum = pSqSum[b] - (a == 0 ? 0 : pSqSum[a - 1]);
  int mean = int(0.5 + (double)sum / (b - a + 1));

  return sqSum - mean * 2 * sum + mean * mean * (b - a + 1);
}

int quantize(int from ,int parts){
  if(from == n)
    return 0;
  if(parts == 0)
    return INF;
  int &ret = cache[from][parts];
  if(ret!=-1)
    return ret;
  
  ret = INF;
  for (int partSize = 1; from + partSize <= n; partSize++) {
    ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
  }

  return ret;
}
void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    memset(cache, -1, sizeof(cache));
    input();
    calcPartial();
    cout << quantize(0, s) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}