#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

string encoded;

void input(){
  cin >> encoded;
}

string solve(string::iterator& it){
  char firstChar = *(it++);
  if(firstChar == 'w'||firstChar=='b'){
    return string(1, firstChar);
  }

  string upLeft = solve(it);
  string upRight = solve(it);
  string downLeft = solve(it);
  string downRight = solve(it);

  return string(1, 'x') + downLeft + downRight + upLeft + upRight;
}

void solution(){
  int tc;
  cin >> tc;
  while(tc--){
    input();
    string::iterator it = encoded.begin();
    cout << solve(it) << '\n';
  }
}

int main() {
  fastio;
  solution();
}