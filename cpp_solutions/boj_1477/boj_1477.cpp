#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M, L;
vector<int> v;

bool isValid(int len){
    int cnt = 0;

    for (int i = 0; i <= N; i++){
        int dist = v[i + 1] - v[i];

        cnt = cnt + dist / len - (dist % len == 0);
    }

    return cnt <= M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> L;

    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(L);

    sort(v.begin(), v.end());

    int lo = 1, hi = L - 2;

    while (lo < hi) {
        int mid = (lo + hi) / 2;

        if (isValid(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo;
}