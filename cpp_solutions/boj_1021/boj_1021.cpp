#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int n, m,left,right,ans=0;
  cin >> n >> m;
  deque<int> dq;
  for (int i = 1; i < n+1;i++) dq.push_back(i);

  while (m--){
    int num;
    cin >> num;

    for (int i = 0; i < dq.size();i++){
      if(dq[i]==num){
        left = i;
        right = dq.size() - i - 1;
        break;
      }
    }
    if(left<=right){
      while(1){
        if(dq.front()==num)
          break;
        dq.push_back(dq.front());
        dq.pop_front();
        ans++;
      }
      dq.pop_front();
    }else{
      while(1){
        if(dq.front()==num)
          break;
        dq.push_front(dq.back());
        dq.pop_back();
        ans++;
      }
      dq.pop_front();
    }
  }
  cout << ans<<'\n';
}