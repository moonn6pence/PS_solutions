#include <iostream>
#include <vector>
using namespace std;

int wn, mn;
vector<int> w; // weight
vector<int> m; // marble
bool dp[31][31001];

void dpSolve(){
  dp[0][15501] = true;
  dp[0][15501 - w[0]] = true;
  dp[0][15501 + w[0]] = true;

  for (int i = 1; i < wn; i++){
    for (int j = 500; j <= 30501; j++){
      dp[i][j] = dp[i - 1][j - w[i]] || dp[i - 1][j] || dp[i - 1][j + w[i]];
    }
  }
}

void solve(int idx){
  if (m[idx]>15000){
    cout << "N ";
    return;
  }

  cout << (dp[wn - 1][m[idx] + 15501] ? "Y " : "N ");
}

void input(){
  int weight;

  cin >> wn;
  for (int i = 0; i < wn; i++){
    cin >> weight;
    w.push_back(weight);
  }

  cin >> mn;
  for (int i = 0; i < mn; i++){
    cin >> weight;
    m.push_back(weight);
  }
}

void solution(){
  input();
  dpSolve();
  for (int i = 0; i < mn; i++)
  {
    solve(i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  solution();
}