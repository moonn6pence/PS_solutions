#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool map[201][201];
int plan[1000];
int parent[201];

void input(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; i++) cin >> plan[i];
}

int find(int x){
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unionGroup(int x, int y){
    x = find(x);
    y = find(y);

    if (x < y){
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

string solve(){
    
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if(map[i][j] == 1 && find(i) != find(j)){
                unionGroup(i, j);
            }
        }
    }


    for (int i = 1; i < M; i++){
        if (find(plan[i]) != find(plan[i - 1])){
            return "NO";
        }
    }

    return "YES";
}

void solution(){
    input();
    cout << solve();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}