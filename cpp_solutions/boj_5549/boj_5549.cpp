#include <bits/stdc++.h>

using namespace std;
int N, M, K;
char area[1001][1001];
int dpJ[1001][1001], dpO[1001][1001], dpI[1001][1001];

int cacheJ(int x, int y){
    if (x == 0 || y == 0) return 0;

    int &ret = dpJ[x][y];

    if (ret != -1) return ret;

    return ret = (area[x][y] == 'J') + cacheJ(x - 1, y) + cacheJ(x, y - 1) - cacheJ(x - 1, y - 1);
}

int cacheO(int x, int y){
    if (x == 0 || y == 0) return 0;

    int &ret = dpO[x][y];

    if (ret != -1) return ret;

    return ret = (area[x][y] == 'O') + cacheO(x - 1, y) + cacheO(x, y - 1) - cacheO(x - 1, y - 1);
}

int cacheI(int x, int y){
    if (x == 0 || y == 0) return 0;

    int &ret = dpI[x][y];

    if (ret != -1) return ret;

    return ret = (area[x][y] == 'I') + cacheI(x - 1, y) + cacheI(x, y - 1) - cacheI(x - 1, y - 1);
}

int solveJ(int a, int b, int c, int d){
    return cacheJ(c, d) - cacheJ(c, b - 1) - cacheJ(a - 1, d) + cacheJ(a - 1, b - 1);
}

int solveO(int a, int b, int c, int d){
    return cacheO(c, d) - cacheO(c, b - 1) - cacheO(a - 1, d) + cacheO(a - 1, b - 1);
}

int solveI(int a, int b, int c, int d){
    return cacheI(c, d) - cacheI(c, b - 1) - cacheI(a - 1, d) + cacheI(a - 1, b - 1);
}

void solution(){
    int a, b, c, d;
    string tmp;

    cin >> M >> N >> K;

    for (int j = 0; j <= N; j++){
        area[0][j] = 'X';
    }

    for (int i = 1; i <= M; i++){
        cin >> tmp;

        area[i][0] = 'X';

        for (int j = 1; j <= N; j++){
            area[i][j] = tmp[j - 1];
        }
    }

    fill(&dpJ[0][0], &dpJ[1000][1001], -1);
    fill(&dpO[0][0], &dpO[1000][1001], -1);
    fill(&dpI[0][0], &dpI[1000][1001], -1);

    for (int i = 0; i < K; i++){
        cin >> a >> b >> c >> d;
        cout << solveJ(a, b, c, d) << ' ';
        cout << solveO(a, b, c, d) << ' ';
        cout << solveI(a, b, c, d) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}