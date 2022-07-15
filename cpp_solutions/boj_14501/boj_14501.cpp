#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef pair<int, int> pii;

int n,profit,sum,day;
vector<pii> table;

void backtrack(){
  int firstFree = -1;
  for (int i = day; i < n;i++){
    if(i+table[i].first<=n){
      firstFree = i;
      break;
    }
  }
  if (firstFree==-1)
  {
    if (profit < sum)
    {
      profit = sum;
    }
    return;
  }

  for (int i = firstFree; i < n; i++)
  {
    if(i + table[i].first <= n){
      day = i + table[i].first;
      sum += table[i].second;
      backtrack();
      sum -= table[i].second;
    }
  }

  return;
}

void input(){
  cin >> n;
  int t, p;
  for (int i = 0; i < n; i++)
  {
    cin >> t >> p;
    table.push_back({t, p});
  }
}

void solution(){
  input();
  backtrack();
  cout << profit;
}

int main() {
  solution();

  fastio;
}