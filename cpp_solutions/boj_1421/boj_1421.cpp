#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    long long N, C, W, tree[50], t_max = 0;

    cin >> N >> C >> W;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        t_max = max(t_max, tree[i]);
    }

    long long profit = 0;

    for (int i = 1; i <= t_max; i++) {
        long long sum = 0;

        for (int j = 0; j < N; j++) {
            if (tree[j] < i) continue;

            int tmp = i * W * (tree[j] / i) - C * (tree[j] / i - 1 + (tree[j] % i != 0));
            if (tmp > 0) sum += tmp;
        }

        profit = max(profit, sum);
    }

    cout << profit;
}