#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9;
int N;
int point[1000][2];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> point[i][0] >> point[i][1];
    }
}

int getDistanceBetween(int i, int j){
    int a = point[i][0] - point[j][0];
    int b = point[i][1] - point[j][1];

    return a * a + b * b;
}

void solve(){
    int ret, ans, minDist = INF;

    for (int i = 0; i < N; i++){
        ret = -1;
        for (int j = 0; j < N; j++){
            ret = max(ret, getDistanceBetween(i, j));
        }

        if (ret < minDist){
            minDist = ret;
            ans = i;
        }
    }

    cout << point[ans][0] << " " << point[ans][1];
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}