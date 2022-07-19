#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int tc, n;
int preorder[1000];
int inorder[1000];
int lookup[1001];

void input(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> preorder[i];
  }
  for (int i = 0; i < n; i++){
    cin >> inorder[i];
  }
}

void memoIndex(){
  for (int i = 0; i < n;i++){
    lookup[inorder[i]] = i;
  }
}

void solve(int inS,int inE,int preS,int preE){
  if (preE < preS || inE < inS)
    return;

  int root = preorder[preS];

  solve(inS, lookup[root] - 1, preS + 1, preS + lookup[root] - inS);
  solve(lookup[root] + 1, inE, preS + lookup[root] - inS + 1, preE);
  cout << root << ' ';
}

void solution(){
  cin >> tc;
  while (tc--){
    input();
    memoIndex();
    solve(0, n - 1, 0, n - 1);
    cout << '\n';
  }
}

int main() {
  fastio;
  solution();
}