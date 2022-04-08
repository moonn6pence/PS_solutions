#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  long long n,sum=0;
  string s,buffer="";
  cin >> n;
  cin >> s;
  for (int i = 0; i < n+1;i++){
    if(i<n && isdigit(s[i])) buffer += s[i];
    else if (!buffer.empty())
    {
      sum += stoi(buffer);
      buffer = "";
    }
  }
  cout << sum;
}