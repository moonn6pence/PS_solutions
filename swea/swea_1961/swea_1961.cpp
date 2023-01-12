#include <bits/stdc++.h>

using namespace std;
int N;
int arr[7][7];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
}

void solve(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << arr[N - 1 - j][i];
        }

        cout << ' ';
        for (int j = 0; j < N; j++){
            cout << arr[N - 1 - i][N - 1 - j];
        }

        cout << ' ';
        for (int j = 0; j < N; j++){
            cout << arr[j][N - 1 - i];
        }
        cout << '\n';
    }
}

void solution(){
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++){
        input();
        cout << '#' << tc <<'\n';
        solve();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}