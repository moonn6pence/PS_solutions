#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Info{
  string s;
  int d, m, y;
  bool operator< (const Info& i) const{
    if(y!=i.y)
      return y < i.y;
    if(m!=i.m)
      return m < i.m;
    return d < i.d;
  }
};

int main()
{
  fastio;
  int n;
  cin >> n;
  vector<Info> v(n);
  for(auto& i:v){
    cin >> i.s >> i.d >> i.m >> i.y;
  }
  auto min = min_element(v.begin(), v.end());
  auto max = max_element(v.begin(), v.end());
  cout << max->s << '\n' << min->s << '\n';
}