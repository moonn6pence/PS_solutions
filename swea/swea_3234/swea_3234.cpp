#include <bits/stdc++.h>

using namespace std;
int N, total;
int W[9];
bool visited[9];
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int binPow[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void init(){
    memset(visited, false, sizeof(visited));
    total = 0;
}

void input(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> W[i];
    for (auto& weight : W) total += weight;
}

int backtrack(int left, int right, int cnt){
    if (cnt == N) return 1;

    if (left >= total - left) return fact[N - cnt] * binPow[N - cnt];

    int ret = 0;

    for (int i = 0; i < N; i++){
        if (visited[i]) continue;

        visited[i] = true;
        ret += backtrack(left + W[i], right, cnt + 1);

        if (left >= right + W[i]){
            ret += backtrack(left, right + W[i], cnt + 1);
        }

        visited[i] = false;
    }

    return ret;
}

void solution(){
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++){
        init();
        input();
        cout << '#' << i << ' ' << backtrack(0, 0, 0) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}