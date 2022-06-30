#include <string>
#include <iostream>
#include <memory.h>

using namespace std;
int c, n;
char board[5][5];
string word;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dp[5][5][10];

bool findNext(int y,int x,int index){
  int nextIndex = index + 1;
  if (nextIndex >= word.size())
  {
    return true;
  }

  int nx,ny;
  for (int d = 0; d < 8; d++)
  {
    nx = x + dx[d];
    ny = y + dy[d];
    if((nx>=0)&&(nx<5)&&(ny>=0)&&(ny<5)){
      if(dp[ny][nx][nextIndex]&&(board[ny][nx]==word[nextIndex])){
        if(findNext(ny, nx, nextIndex))
          return true;
      }
    }
  }

  dp[y][x][index] = false;
  return false;
}

bool findFirst(void){
  for (int i = 0; i < 5;i++){
    for (int j = 0; j < 5;j++){
      if(board[i][j]==word[0]){
        if(findNext(i, j, 0))
          return true;
      }
    }
  }
  return false;
}

void solve(){
  cin >> c;
  for (int i = 0; i < c;i++){
    for (int j = 0; j < 5;j++){
      cin >> board[j];
    }

    cin >> n;
    for (int j = 0; j < n;j++){
      memset(dp, true, sizeof(dp));
      cin >> word;
      if(findFirst())
        cout << word << " YES\n";
      else
        cout << word << " NO\n";
    }
  }
}

int main() {
  solve();

  return 0;
}