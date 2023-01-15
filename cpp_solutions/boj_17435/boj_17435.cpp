#include <bits/stdc++.h>

using namespace std;
int M, maxK = 19;
int ST[20][200001];

void input(){
    cin >> M;
    for (int i = 1; i <= M; i++){
        cin >> ST[0][i];
    }
}

void initSparseTable(){
    for (int k = 1; k < maxK; k++){
        for (int i = 1; i <= M; i++){
            ST[k][i] = ST[k - 1][ST[k - 1][i]];
        }
    }
}

int query(int n, int x){
    for (int i = maxK; i >= 0; i--){
        if (n & (1 << i)) x = ST[i][x];
    }

    return x;
}

void solution(){
    input();
    initSparseTable();
    int Q, n, x;
    cin >> Q;
    while (Q--){
        cin >> n >> x;
        cout << query(n, x) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}