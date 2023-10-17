#include <bits/stdc++.h>

using namespace std;
int N, arr[10] = {0,}, answer[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int cnt = 0;

        for (int j = 0; j < N; j++) {
            if (cnt == arr[i] && answer[j] == 0) {
                answer[j] = i + 1;
                break;
            }
            if (answer[j] == 0) cnt++;
        }
    }

    for (int i = 0; i < N; i++) cout << answer[i] << ' ';
}