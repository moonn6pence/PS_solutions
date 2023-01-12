#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9;
int N, M;
int A[20], B[20];

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];
}

int solve(){
    int ret = -INF;
    if (N > M) {
        swap(A, B);
        swap(N, M);
    }

    for (int b = 0; b < M - N + 1; b++){
        int tmp = 0;

        for (int a = 0; a < N; a++){
            tmp += A[a] * B[a + b];
        }
        
        ret = max(ret, tmp);
    }

    return ret;
}

void solution(){
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++){
        input();
        cout << '#' << i << ' ' << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}