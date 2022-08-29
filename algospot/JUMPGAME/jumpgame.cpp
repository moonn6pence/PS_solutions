#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int boardSize, board[100][100];
int cache[100][100];

int solve(int y,int x){
  if (x >= boardSize || y >= boardSize) return 0;
  if (x == boardSize-1 && y == boardSize-1) return 1;

  int &ret = cache[y][x];
  if( ret != -1) return ret;
  int jumpSize = board[y][x];

  return ret = (solve(y + jumpSize, x)) || (solve(y, x + jumpSize));
}

void input(){
  cin >> boardSize;
  for (int i = 0; i < boardSize; i++){
    for (int j = 0; j < boardSize; j++){
      cin >> board[i][j];
    }
  }
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    memset(cache, -1, sizeof(cache));
    input();
    cout << (solve(0, 0) == 1 ? "YES" : "NO") << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}