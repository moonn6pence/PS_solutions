#include <iostream>
#define MAX_LEN 1000000
using namespace std;
typedef long long ll;

ll seg[MAX_LEN * 4];
ll arr[MAX_LEN];
int N, M, K;

void input(){
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++){
    cin >> arr[i];
  }
}

ll makeSeg(int node, int start, int end){
  if (start == end)
    return seg[node] = arr[start];
  int mid = (start + end) / 2;
  return seg[node] = makeSeg(node * 2, start, mid) + makeSeg(node * 2 + 1, mid + 1, end);
}

void updateSeg(int node, int start, int end, int idx, ll diff){
  if(idx < start || end < idx)
    return;
  seg[node] += diff;
  if (start != end){
    int mid = (start + end) / 2;
    updateSeg(node * 2, start, mid, idx, diff);
    updateSeg(node * 2 + 1, mid + 1, end, idx, diff);
  }
}

ll getPsum(int node, int start, int end, int left, int right){
  if(left > end || right < start)
    return 0;
  if(left <= start && end <= right)
    return seg[node];
  int mid = (start + end) / 2;
  return getPsum(node * 2, start, mid, left, right) + getPsum(node * 2 + 1, mid + 1, end, left, right);
}

void solution(){
  input();
  int tmp = M + K, a, b;
  ll c;
  makeSeg(1, 0, N - 1);
  while (tmp--)
  {
    cin >> a >> b >> c;
    if(a == 1){
      updateSeg(1, 0, N - 1, b - 1, c - arr[b - 1]);
      arr[b - 1] = c;
    }
    else
    {
      cout << getPsum(1, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}