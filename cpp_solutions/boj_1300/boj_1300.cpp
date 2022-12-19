#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, k;

void input(){
    cin >> N >> k;
}

int solve(int k){
    int lo = 1, hi = k;
    while(lo <= hi){
        ll cnt = 0;
        int mid = (lo + hi) / 2;

        for (int i = 1; i <= N; i++){
            cnt += min(mid / i, N);
        }

        if(cnt >= k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

void solution(){
    input();
    cout << solve(k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}
