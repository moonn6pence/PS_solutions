#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 100001
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii,vector<pii>,less<pii>> max_pq;
priority_queue<pii,vector<pii>,greater<pii>> min_pq;
int n, m;
int level[MAX];

void recommend(int flag){
  int p, l;
  if (flag == 1)
  {
    while(1){
      l = max_pq.top().first;
      p = max_pq.top().second;
      if(level[p]==l)
        break;
      max_pq.pop();
    }
    cout << p << '\n';
  }
  else
  {
    while(1){
      l = min_pq.top().first;
      p = min_pq.top().second;
      if(level[p]==l)
        break;
      min_pq.pop();
    }
    cout << p << '\n';
  }
}

void add(int P,int L){
  level[P] = L;
  max_pq.push({L, P});
  min_pq.push({L, P});
}

void solved(int P){
  level[P] = 0;
}

void input(){
  cin >> n;
  int L, P;
  string cmd;
  while (n--)
  {
    cin >> P >> L;
    max_pq.push({L, P});
    min_pq.push({L, P});
    level[P] = L;
  }
  return;
}
void command(){
  int L, P, flag;
  string cmd;
  cin >> m;
  while(m--){
    cin >> cmd;
    if(cmd=="recommend"){
      cin >> flag;
      recommend(flag);
    }
    else if (cmd == "add")
    {
      cin >> P >> L;
      add(P, L);
    }
    else
    {
      cin >> P;
      solved(P);
    }
  }
  return;
}

void solution(){
  input();
  command();
  cout << '\n';
}

int main() {
  fastio;
  solution();
}