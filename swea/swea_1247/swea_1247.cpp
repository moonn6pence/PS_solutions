#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX = 12;
int N;
pii home;
vector<pii> client;
int cache[(1 << MAX)][MAX];
int dist[MAX][MAX];

void init(){
    fill(&cache[0][0], &cache[(1 << MAX) - 1][MAX], 0);
    // memset(cache, 0, sizeof(cache));
    client.clear();
}

void input(){
    cin >> N;
    int a, b;
    cin >> a >> b;
    client.push_back({a, b});

    cin >> a >> b;
    home = {a, b};

    for (int i = 0; i < N; i++){
        cin >> a >> b;
        client.push_back({a, b});
    }

    N += 1;
}

int getDist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void setDist(){
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            dist[i][j] = getDist(client[i], client[j]);
            if (i != j) dist[j][i] = dist[i][j];
        }
    }
}

int tsp(int state, int node){
    if (state == (1 << N) - 1) return getDist(client[node], home);

    int &ret = cache[state][node];

    if (ret > 0) return ret;

    ret = INF;

    for (int i = 0; i < N; i++){
        if (!(state & (1 << i))){
            ret = min(ret, tsp(state | (1 << i), i) + dist[node][i]);
        }
    }

    return ret;
}

void solution(){
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++){
        init();
        input();
        setDist();
        cout << '#' << i << ' ' << tsp(1, 0) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}