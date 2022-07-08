#include <iostream>
#include <memory.h>

using namespace std;
int h, w;
char board[20][20];
bool visited[20][20];
int total;

const int blockType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {1, 0}, {1, 1}}};

int backtrack(){
  bool flag=false;
  int startY = -1, startX = -1;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w;j++){
      if (!visited[i][j])
      {
        startY = i;
        startX = j;
        flag = true;
        break;
      }
    }
    if (flag)
    {
      break;
    }
  }
  if (startY==-1)
  {
    return 1;
  }
  int nx, ny;
  int ret = 0,cnt;
  bool able[3];

  for (int k = 0; k < 4;k++){
    cnt = 0;
    for (int l = 0; l < 3; l++)
    {
      able[l] = false;
      ny = startY + blockType[k][l][0];
      nx = startX + blockType[k][l][1];
      if((0<=ny)&&(ny<h)&&(0<=nx)&&(nx<w)&&!visited[ny][nx]){
        visited[ny][nx] = true;
        cnt++;
        able[l] = true;
      }
    }
    if (cnt == 3)
    {
      ret += backtrack();
    }
    for (int l = 0; l < 3;l++){
      ny = startY + blockType[k][l][0];
      nx = startX + blockType[k][l][1];
      if(able[l]&&board[ny][nx]!='#'){
        visited[ny][nx] = false;
      }
    }
  }
  return ret;
}

void input(){
  char tmp;
  cin >> h >> w;
  total = h*w;
  for (int i = 0; i < h;i++){
    for (int j = 0; j < w;j++){
      cin >> tmp;
      board[i][j] = tmp;
      if(tmp=='#'){
        total--;
        visited[i][j] = true;
      }
    }
  }
}

void solution(){
  int c,ans;
  char tmp;
  cin >> c;
  while(c--){
    ans = 0;
    memset(visited, false, sizeof(visited));
    input();
    if (total % 3 == 0)
      ans = backtrack();
    cout << ans << '\n';
  }
}

int main(){
  solution();

  return 0;
}