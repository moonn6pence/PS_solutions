#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int n,num;
  priority_queue<int,vector<int>,greater<int>> pq;
  cin >> n;
  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      cin >> num;
      if(i==0)
        pq.push(num);
      else{
        if(pq.top()<num){
          pq.pop();
          pq.push(num);
        }
      }
    }
  }
  cout << pq.top()<<'\n';
}