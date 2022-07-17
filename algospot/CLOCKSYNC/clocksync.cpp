#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int INF = 999;

int clocks[16];
bool linked[10][16]={
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
  {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
  {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
  {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool isAllSync(){
  bool flag = true;
  for (int i = 0; i < 16; i++)
  {
    if(clocks[i] != 12){
      flag = false;
      break;
    }
  }
  return flag;
}

void pushSwitch(int num){
  for (int i = 0; i < 16; i++){
    if(linked[num][i]){
      clocks[i] += 3;
    }
    if(clocks[i]==15){
      clocks[i] = 3;
    }
  }
}

int solve(int cnt){
  if(cnt == 10){
    return isAllSync() ? 0 : INF;
  }
  int ret = INF;
  for (int i = 0; i < 4; i++)
  {
    ret = min(ret, i + solve(cnt + 1));
    pushSwitch(cnt);
  }

  return ret;
}

void input(){
  for (int i = 0; i < 16; i++)
  {
    cin >> clocks[i];
  }
}

void solution(){
  int t,ans;
  cin >> t;
  while(t--){
    input();
    ans = solve(0);
    if(ans>=999)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
}

int main(){
  solution();
  fastio;
}