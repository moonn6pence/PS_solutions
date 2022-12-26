#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int cache[1000001][2];
bool visited[1000001];
vector<int> edge[1000001];

void input(){
    cin >> N;
    int u, v;

    for (int i = 1; i < N; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

int solve(int cur, int parent, bool isEarlyAdapter){
    int &ret = cache[cur][isEarlyAdapter];
    if (ret != -1)
        return ret;

    int childSize = edge[cur].size();
    int ans = 0;

    if(!isEarlyAdapter){
        for (int i = 0; i < childSize; i++){
            int child = edge[cur][i];
            if (child == parent) continue;
            ans += solve(child, cur, true);
        }

        ret = ans;
    } else {
        for (int i = 0; i < childSize; i++){
            int child = edge[cur][i];
            if (child == parent) continue;
            ans += min(solve(child, cur, true), solve(child, cur, false));
        }

        ret = ans + 1;
    }

    return ret;
}

void solution(){
    input();
    memset(cache, -1, sizeof(cache));
    cout << min(solve(1, 0, 0), solve(1, 0, 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}