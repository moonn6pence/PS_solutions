#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> trust[10001];

int bfs(int start){
    bool visited[10001] = {false,};
    vector<int> tmp;
    queue<int> order;
    order.push(start);
    visited[start] = true;
    int cnt = 1;

    while(!order.empty()) {
        int cur = order.front();
        order.pop();

        for(int node : trust[cur]) {
            if (visited[node]) continue;

            order.push(node);
            visited[node] = true;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, max_hacked = 0;
    vector<int> answer;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        trust[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        int hacked = bfs(i);

        if (max_hacked < hacked) {
            answer.clear();
            answer.push_back(i);
            max_hacked = hacked;
        } else if (max_hacked == hacked) {
            answer.push_back(i);
        }
    }

    for(int x : answer){
        cout << x << ' ';
    }
}