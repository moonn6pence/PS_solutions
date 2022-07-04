#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int c,n,m;
bool isFriend[10][10]={false,};
bool visited[10] = {false};

int backtrack(){
  int firstFree = -1;
  for (int i = 0; i < n;i++){
    if(!visited[i]){
      firstFree = i;
      break;
    }
  }

  if (firstFree == -1)
  {
    return 1;
  }

  int ret = 0;
  for (int i = firstFree+1; i < n; i++)
  {
    if (!visited[i]&&isFriend[firstFree][i])
    {
      visited[i] = visited[firstFree] = true;
      ret += backtrack();
      visited[i] = visited[firstFree] = false;
    }
  }
  return ret;
}

void exhaustiveSearch(){
  int ans = 0;
  ans = backtrack();
  cout << ans << '\n';
}

void input(){
  int p1, p2;
  cin >> n >> m;
  for (int i = 0; i < m;i++){
    cin >> p1 >> p2;
    isFriend[p1][p2] = true;
    isFriend[p2][p1] = true;
  }
}

void solution(){
  cin >> c;
  while(c--){
    memset(visited, false, sizeof(visited));
    memset(isFriend, false, sizeof(isFriend));
    input();
    exhaustiveSearch();
  }
}

int main() {
  solution();
  return 0;
}