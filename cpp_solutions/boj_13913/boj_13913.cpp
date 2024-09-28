#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int UPBOUND = 100000;
int visited[100001];
int from[100001];
int N,K;

void input(){
    cin >> N >> K;
}

int bfs(){
    queue<int> order;
    order.push(N);
    visited[N] = 1;
    from[N] = N;

    while (!order.empty()){
        int cur = order.front();
        order.pop();

        if (cur == K) return visited[K]-1;

        int next;

        next = cur * 2;
        if (next <= UPBOUND && !visited[next]) {
            visited[next] = visited[cur] + 1;
            from[next] = cur;
            if (next == K) return visited[K]-1;
            order.push({next});
        }

        next = cur - 1;
        if (next >= 0 && !visited[next]) {
            visited[next] = visited[cur] + 1;
            from[next] = cur;
            if (next == K) return visited[K]-1;
            order.push({next});
        }

        next = cur + 1;
        if (next <= UPBOUND && !visited[next]) {
            visited[next] = visited[cur] + 1;
            from[next] = cur;
            if (next == K) return visited[K]-1;
            order.push({next});
        }
    }

    return -1;

}

void track_route(){
    stack<int> routes;
    int node = K;

    routes.push(K);
    
    while (node != N) {
        node = from[routes.top()];
        routes.push(node);
    }

    while (!routes.empty()){
        cout << routes.top() << ' ';
        routes.pop();
    }
}

void solution(){
    cout << bfs() << '\n';
    track_route();
}

int main(){
    input();
    solution();
}