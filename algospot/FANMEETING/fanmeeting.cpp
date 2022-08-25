#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int c;
string member, fan;

vector<int> multiply(const vector<int>& A,const vector<int>& B){
  vector<int> C(A.size() + B.size() + 1, 0);
  for (int i = 0; i < A.size();i++){
    for (int j = 0; j < B.size();j++){
      C[i + j] += A[i] * B[j];
    }
  }
  return C;
}

void addTo(vector<int>& A,const vector<int>& B, int k){
  A.resize(max(A.size(), B.size() + k));
  for (int i = 0; i < B.size();i++){
    A[i + k] += B[i];
  }
}

void subFrom(vector<int>& A,const vector<int>& B){
  A.resize(max(A.size(), B.size()) + 1);
  for (int i = 0; i < B.size(); i++){
    A[i] -= B[i];
  }
}

vector<int> karatsuba(const vector<int>& A, const vector<int>& B){
  int alen = A.size(), blen = B.size();
  if(alen < blen)
    return karatsuba(B, A);
  if(alen == 0 || blen == 0)
    return vector<int>();
  if(alen <= 50){
    return multiply(A, B);
  }
  
  int half = alen / 2;
  vector<int> A0(A.begin(), A.begin() + half);
  vector<int> A1(A.begin() + half, A.end());
  vector<int> B0(B.begin(), B.begin() + min<int>(blen, half));
  vector<int> B1(B.begin() + min<int>(blen, half), B.end());

  vector<int> Z2 = karatsuba(A1, B1);
  vector<int> Z0 = karatsuba(A0, B0);

  addTo(A0, A1, 0);
  addTo(B0, B1, 0);

  vector<int> Z1 = karatsuba(A0, B0);
  subFrom(Z1, Z0);
  subFrom(Z1, Z2);

  vector<int> ret;
  addTo(ret, Z0, 0);
  addTo(ret, Z1, half);
  addTo(ret, Z2, half + half);
  return ret;
}

int solve(){
  int n = member.size(), m = fan.size();
  vector<int> A(n), B(m);
  for (int i = 0; i < n; i++){
    A[i] = (member[i] == 'M');
  }

  for (int i = 0; i < m; i++){
    B[m - i - 1] = (fan[i] == 'M');
  }

  vector<int> C = karatsuba(A, B);
  int ans = 0;
  for (int i = n - 1; i < m; i++){
    if (C[i] == 0){
      ans++;
    }
  }

  return ans;
}

void input(){
  cin >> member;
  cin >> fan;
}

void solution(){
  cin >> c;
  while(c--){
    member.clear();
    fan.clear();
    input();
    cout << solve() << '\n';
  }
}

int main() {
  fastio;
  solution();
}