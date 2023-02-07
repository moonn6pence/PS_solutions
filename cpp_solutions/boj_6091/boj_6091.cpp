#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
int N;
int parent[1024];
int cnt[1024];
priority_queue<pipii, vector<pipii>, greater<pipii>> adj;
vector<int> answer[1024];

void input() {
    cin >> N;
    int tmp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> tmp;
            adj.push({tmp, {i, j}});
        }
    }
}

int find(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

int Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) {
        parent[b] = a;
        cnt[a] += cnt[b];
        return cnt[a];
    }

    parent[a] = b;
    cnt[b] += cnt[a];
    return cnt[b];

}

void solve() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }

    while (true) {
        int node1 = adj.top().second.first;
        int node2 = adj.top().second.second;
        adj.pop();

        if (find(node1) == find(node2)) continue;

        answer[node1].push_back(node2);
        answer[node2].push_back(node1);

        if (Union(node1, node2) == N) return;
    }
}

void output() {
    for (int i = 0; i < N; i++) {
        sort(answer[i].begin(), answer[i].end());
        cout << answer[i].size() << ' ';
        for(int node : answer[i]){
            cout << node + 1 << ' ';
        }
        cout << '\n';
    }
}

void solution() {
    input();
    solve();
    output();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}