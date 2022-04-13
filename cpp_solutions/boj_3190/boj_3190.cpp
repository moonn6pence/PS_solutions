#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  fastio;
  deque<pair<int, int>> snake{{1,1}};
  deque<pair<int, char>> move;
  int n, k,l,ans=0,dir=1;
  bool flag=true;

  cin >> n >> k;
  while(k--)
  {
    int x, y; cin >> x >> y;
    board[x][y] = 1;
  }

  cin >> l;
  while(l--){
    int x;
    char dir;
    cin >> x >> dir;
    move.push_back({x, dir});
  }
  while(1){
    ans++;
    int x = snake.front().first;
    int y = snake.front().second;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    for(auto &body:snake){
      if (body.first==nx && body.second==ny){
        flag = false;
        break;
      }
    }
    if(nx>n||nx<1||ny>n||ny<1||!flag){
      break;
    }

    snake.push_front({nx, ny});
    if(!board[nx][ny]){
      snake.pop_back();
    }else{
      board[nx][ny] = 0;
    }

    if(move.size() && move.front().first==ans){
      if(move.front().second=='D'){
        dir = (dir + 1) % 4;
      }else if(move.front().second=='L'){
        dir = (dir + 3) % 4;
      }
      move.pop_front();
    }
  }
  cout << ans<<'\n';
}