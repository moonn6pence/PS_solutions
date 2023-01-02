#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int feed[11][11], A[11][11], dead[11][11];
deque<int> tree[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    }

    for (int i = 0; i < M; i++){
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}

void init(){
    fill(&feed[0][0], &feed[N][N + 1], 5);

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            sort(tree[i][j].begin(), tree[i][j].end());
    }
}

void spring(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int len = tree[i][j].size();

            while (len--){
                int youngest = tree[i][j].front();
                tree[i][j].pop_front();
                if (youngest <= feed[i][j]){
                    tree[i][j].push_back(youngest + 1);
                    feed[i][j] -= youngest;
                }
                else
                    dead[i][j] += youngest / 2;
            }
        }
    }
}

void summer(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            feed[i][j] += dead[i][j];
            dead[i][j] = 0;
        }
    }
}

void fall(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            for (auto iter : tree[i][j]){
                if(iter % 5 == 0){
                    for (int k = 0; k < 8; k++){
                        int x = i + dx[k], y = j + dy[k];
                        if(x < 1 || x > N) continue;
                        if(y < 1 || y > N) continue;

                        tree[x][y].push_front(1);
                    }
                }
            }
        }
    }
}

void winter(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            feed[i][j] += A[i][j];
        }
    }
}

void annualSimulation(){
    spring();
    summer();
    fall();
    winter();
}

void solution(){
    int ans = 0;
    input();
    init();
    while (K--) annualSimulation();

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            ans += tree[i][j].size();
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}