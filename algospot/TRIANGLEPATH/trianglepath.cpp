#include <iostream>
#include <memory.h>

using namespace std;

int tri[100][100];
int cache[100][100];
int n;

void input(){
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < i + 1; j++){
      cin >> tri[i][j];
    }
  }
}

int solve(int y, int x){

  if(y == n-1){
    return tri[y][x];
  }

  int &ret = cache[y][x];
  if(ret!=-1){
    return ret;
  }

  ret = tri[y][x] + max(solve(y +1, x), solve(y + 1, x + 1));

  return ret;
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    input();
    memset(cache,-1,sizeof(cache));
    cout << solve(0, 0) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}