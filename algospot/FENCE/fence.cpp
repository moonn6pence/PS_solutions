#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int c,n;
vector<int> h;

int solve(int left, int right){
  if(left==right) return h[left];

  int mid = (left + right) / 2;
  int ret = max(solve(left, mid), solve(mid + 1, right));

  int low = mid, high = mid + 1;
  int height = min(h[low], h[high]);

  ret = max(ret, height * 2);

  while(left < low || high < right){
    if (left < low && (right == high || h[low - 1] > h[high + 1]))
    {
      --low;
      height = min(height, h[low]);
    }
    else
    {
      ++high;
      height = min(height, h[high]);
    }

    ret = max(ret, height * (high - low + 1));
  }

  return ret;
}

void input(){
  cin >> n;
  int tmp;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    h.push_back(tmp);
  }
}

void solution(){
  cin >> c;
  while(c--){
    input();
    cout << solve(0,n-1) << '\n';
    h.clear();
  }
}

int main() {
  fastio;
  solution();
}