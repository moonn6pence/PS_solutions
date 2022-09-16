#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int INF = 987654321;
string N;
int cache[10002];

void input(){
  cin >> N;
}

int classify(int a, int b){
  string M = N.substr(a, b - a + 1);
  if(M == string(M.size(), M[0])) return 1;

  bool progressiveFlag = true;
  for (int i = 0; i < M.size() - 1; i++){
    if(M[i + 1] - M[i] != M[1] - M[0]){
      progressiveFlag = false;
    }
  }

  if(progressiveFlag && abs(M[1] - M[0]) == 1) return 2;

  bool alternativeFlag = true;
  for (int i = 0; i < M.size(); i++){
    if(M[i]!=M[i%2]){
      alternativeFlag = false;
    }
  }

  if(alternativeFlag) return 4;
  if(progressiveFlag) return 5;
  return 10;
}

int memorize(int begin){
  if(begin == N.size())
    return 0;
  int &ret = cache[begin];
  if(ret != -1) return ret;

  ret = INF;

  for (int i = 3; i < 6; i++){
    if(begin + i <= N.size()){
      ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
    }
  }

  return ret;
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    input();
    memset(cache, -1, sizeof(cache));
    cout << memorize(0) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}