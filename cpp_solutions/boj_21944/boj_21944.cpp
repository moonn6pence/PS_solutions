#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 100001
using namespace std;

constexpr int INF = 1e9 + 7;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, less<pii>> max_cat[101];
priority_queue<pii, vector<pii>, greater<pii>> min_cat[101];
priority_queue<pii, vector<pii>, less<pii>> max_pq;
priority_queue<pii, vector<pii>, greater<pii>> min_pq;
set<pii> lvlset;

int n, m;
int lookup_lvl[MAX];

void rcmd1(int G,int x){
  int p, l;
  if (x == 1)
  {
    while(1){
      l = max_cat[G].top().first;
      p = max_cat[G].top().second;
      if(lookup_lvl[p]==l)
        break;
      max_cat[G].pop();
    }
  }else{
    while(1){
      l = min_cat[G].top().first;
      p = min_cat[G].top().second;
      if(lookup_lvl[p]==l)
        break;
      min_cat[G].pop();
    }
  }
  cout << p << '\n';
  return;
}

void rcmd2(int x){
  int p, l;
  if (x == 1)
  {
    while(1){
      l = max_pq.top().first;
      p = max_pq.top().second;
      if(lookup_lvl[p]==l)
        break;
      max_pq.pop();
    }
  }
  else
  {
    while(1){
      l = min_pq.top().first;
      p = min_pq.top().second;
      if(lookup_lvl[p]==l)
        break;
      min_pq.pop();
    }
  }
  cout << p << '\n';
  return;
}

void rcmd3(int x,int L){
  if(x==1){
    auto it = lvlset.upper_bound({L - 1, INF});
    if(it==lvlset.end()){
      cout << -1 << '\n';
      return;
    }
    cout << it->second << '\n';
  }else{
    auto it = lvlset.upper_bound({L, -INF});
    if(it==lvlset.begin()){
      cout << -1 << '\n';
      return;
    }
    cout << prev(it)->second << '\n';
  }
  return;
}

void add(int p,int l,int g){
  max_cat[g].push({l, p});
  min_cat[g].push({l, p});
  max_pq.push({l, p});
  min_pq.push({l, p});
  lvlset.insert({l, p});
  lookup_lvl[p] = l;
}

void solved(int p){
  lvlset.erase({lookup_lvl[p],p});
  lookup_lvl[p] = 0;
}

void input(){
  int p, l, g;
  cin >> n;
  while(n--){
    cin >> p >> l >> g;
    max_cat[g].push({l, p});
    min_cat[g].push({l, p});
    max_pq.push({l, p});
    min_pq.push({l, p});
    lvlset.insert({l, p});
    lookup_lvl[p] = l;
  }
  return;
}

void command(){
  int G, x, L, P;
  string cmd;
  cin >> m;
  while(m--){
    cin >> cmd;
    if(cmd[0]=='r'){
        if (cmd[9] == '3')
      {
        cin >> x >> L;
        rcmd3(x, L);
      }
      else if (cmd[9] == '2')
      {
        cin >> x;
        rcmd2(x);
      }
      else
      {
        cin >> G >> x;
        rcmd1(G, x);
      }
    }else if(cmd[0]=='a'){
      cin >> P >> L >> G;
      add(P, L, G);
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
}

int main() {
  fastio;
  solution();
}