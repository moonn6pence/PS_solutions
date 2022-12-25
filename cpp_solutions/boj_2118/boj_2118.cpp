#include <iostream>
#include <algorithm>

using namespace std;

int sum = 0, N, ans = 1e9;
int dist[50000];

void input(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> dist[i];
        sum += dist[i];
    }
}

void solve(){
    int i = 0, j = 0, pSum = dist[i];
    ans = min(pSum, sum - pSum);
    while (j <= i){
        if (i != N - 1 && pSum <= sum - pSum){
            i++;
            pSum += dist[i];
        } else {
            pSum -= dist[j];
            j++;
        }

        ans = max(ans, min(pSum, sum - pSum));
    }
}

void solution(){
    input();
    solve();
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}