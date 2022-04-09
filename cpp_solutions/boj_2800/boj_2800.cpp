#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
bool visited[201];
bool char_visited[201];
set<string> ans;
string str;
vector<pair<int, int>> pos;

void DFS(int depth,int cur){
  if(depth>=1){
    string s = "";
    for (int i = 0; i < str.size();i++){
      if(char_visited[i]) continue;
      s += str[i];
    }
    ans.insert(s);
  }
  for (int i = cur; i < pos.size();i++){
    if (visited[i])
      continue;
    visited[i] = true;
    char_visited[pos[i].first] = true;
    char_visited[pos[i].second] = true;
    DFS(depth + 1, cur+1);
    visited[i] = false;
    char_visited[pos[i].first] = false;
    char_visited[pos[i].second] = false;
  }
}

int main() {
  fastio;
  cin >> str;
  stack<int> left;
  for (int i = 0; i<str.size(); i++)
  {
    if(str[i]=='('){
      left.push(i);
    }else if(str[i]==')'){
      pos.push_back({left.top(), i});
      left.pop();
    }
  }
  DFS(0, 0);
  for (auto x : ans)
  {
    cout << x <<'\n';
  }
}