#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int N;
vector<ll> A;

void input(){
    ll tmp;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
}

int solve(){
    sort(A.begin(), A.end());

    int cnt = 0;

    for (int i = 0; i < N; i++){
        int lo = 0, hi = N - 1;
        ll cur = A[i];
        while (lo < hi){
            if (i == lo || A[lo] + A[hi] < cur){
                lo++;
                continue;
            }

            if(i == hi || A[lo] + A[hi] > cur){
                hi--;
                continue;
            }

            if(A[lo] + A[hi] == cur){
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

void solution(){
    input();
    cout << solve() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}