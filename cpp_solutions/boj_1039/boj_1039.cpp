#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, K, radix = 1;
map<pii, bool> visited;
int powTen[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

void input(){
    cin >> N >> K;

    int tmp = N;

    while ((int)tmp / 10 ){
        tmp /= 10;
        radix++;
    }
}

int exchange(int num, int i, int j){
    int iValue = num / powTen[i] % 10, jValue = num / powTen[j] % 10;
    int iBefore = iValue * powTen[i], jBefore = jValue * powTen[j];
    int iAfter = iValue * powTen[j], jAfter = jValue * powTen[i];

    return num - iBefore - jBefore + iAfter + jAfter;
}

int BFS(){
    int ret = -1;
    queue<pii> order;
    order.push({N, 0});
    visited[{N, 0}] = true;

    while (!order.empty()){
        int cur, k;
        tie(cur, k) = order.front();
        order.pop();

        if (k == K) {
            ret = max(ret, cur);
            continue;
        }

        for (int i = 0; i < radix - 1; i++){
            int iValue = cur / powTen[i] % 10;

            for (int j = i + 1; j < radix - 1; j++){
                int next = exchange(cur, i, j);
                if (visited[{next, k + 1}]) continue;
                order.push({next, k + 1});
                visited[{next, k + 1}] = true;
            }

            if (iValue != 0) {
                int next = exchange(cur, i, radix - 1);
                if (visited[{next, k + 1}]) continue;
                order.push({next, k + 1});
                visited[{next, k + 1}] = true;
            }
        }
    }

    return ret;
}

void solution(){
    input();
    cout << BFS();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}