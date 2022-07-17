#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 987654321;

int n;
int visited[(1 << 16)][17];
int dist[17][17];

int tsp(int curState,int curNode){
  if (visited[curState][curNode] == -1){

  }
  if (curState == (1 << n) - 1){
    if(dist[curNode][0]){
      return dist[curNode][0];
    }
    return INF;
  }

  if (visited[curState][curNode] != -1)
  {
    return visited[curState][curNode];
  }

  visited[curState][curNode] = INF;
  for (int i = 0; i < n; i++)
  {
    if (dist[curNode][i] == 0 || (curState & (1 << i)))
      continue;

    int nextState = curState | (1 << i);

    if(i == 0 && nextState != ((1<<n)-1))
      continue;

    visited[curState][curNode] = min(visited[curState][curNode], tsp(nextState,i) + dist[curNode][i]);
  }

  return visited[curState][curNode];
}

void input(){
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++){
      cin >> dist[i][j];
    }
  }
}

void solution(){
  input();
  memset(visited, -1, sizeof(visited));
  cout << tsp(1, 0);
}

int main() {
  solution();
  fastio;
}