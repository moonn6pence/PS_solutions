#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int cache[101][101];
string W, S;

bool match(int w,int s){
  int &ret = cache[w][s];
  if(ret!=-1) return ret;
  while (s < S.size() && w < W.size() && (W[w]=='?' || W[w]==S[s])){
    w++;
    s++;
  }
  if(w == W.size())
    return ret = (s == S.size());
  if(W[w] == '*'){
    if (match(w + 1, s) || (s < S.size() && match(w, s + 1))){
      return ret = 1;
    }
  }

  return ret = 0;
}

void input(){
  cin >> W;
}

void output(vector<string>& ans){
  sort(ans.begin(), ans.end());
  for(auto &i:ans){
    cout << i << '\n';
  }
}

void solution(){
  int c,n;
  cin >> c;
  while(c--){
    vector<string> ans;
    input();
    cin >> n;
    while(n--){
      memset(cache, -1, sizeof(cache));
      cin >> S;
      if (match(0, 0)){
        ans.push_back(S);
      }
    }
    output(ans);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}