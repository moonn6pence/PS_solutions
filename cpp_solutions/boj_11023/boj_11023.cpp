#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  string n;
  int sum = 0;
  getline(cin, n);
  string tmp = "";
  int nlen = n.size();
  for (int i = 0; i < nlen;i++){
    tmp += n[i];
    if (n[i]==' '||i==nlen-1){
      sum += stoi(tmp);
      tmp = "";
    }
  }
  cout << sum;
}