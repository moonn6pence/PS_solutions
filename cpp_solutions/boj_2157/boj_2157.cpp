#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
typedef pair<int, int> pii;
int N, M, K;
int cache[301][301];
vector<pii> graph[301];

void input(){

    int a, b, cost;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++){
        cin >> a >> b >> cost;
        if (a < b) graph[a].push_back({b, cost});
    }
}

int solve(int cur, int cnt){

    int &ret = cache[cur][cnt];

    if (ret != -1) return ret;

    if (cur == N) return 0;

    if (cnt >= M) return -INF;

    ret = -INF;
    
    for(auto v : graph[cur]){
        ret = max(ret, solve(v.first, cnt + 1) + v.second);
    }

    return ret;
}

void solution(){
    input();

    fill(&cache[0][0], &cache[300][301], -1);

    cout << solve(1, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
}