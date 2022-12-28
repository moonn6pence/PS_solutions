#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int N, M;

    cin >> N >> M;

    int A[100][100], B[100][100];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << A[i][j] + B[i][j]<<' ';
        }

        cout << '\n';
    }
}