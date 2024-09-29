#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int UBOUND = 500000;
int N,K,visited[UBOUND+1][2];

void input(){
    cin >> N >> K;
}

void bfs(){
    queue<pii> order;
    order.push({N, 0});
    visited[N][0] = 0;

    while (!order.empty()){
        int cur, time;
        tie(cur,time) = order.front();
        order.pop();
        
        int next;

        next = cur * 2;
        if (next <= UBOUND && visited[next][(time+1)%2] == -1) {
            visited[next][(time+1)%2] = time + 1;
            order.push({next,time+1});
        }

        next = cur - 1;
        if (next >= 0 && visited[next][(time+1)%2] == -1) {
            visited[next][(time+1)%2] = time + 1;
            order.push({next,time+1});
        }

        next = cur + 1;
        if (next <= UBOUND && visited[next][(time+1)%2] == -1) {
            visited[next][(time+1)%2] = time + 1;
            order.push({next,time+1});
        }
    }
}

int check(){
    int t=0;
    while(1){
        int pos = K + (t*t+t)/2;
        if (pos > UBOUND) break;
        if (visited[pos][t%2] != -1 && visited[pos][t%2] <= t) return t;
        t++;
    }

    return -1;
}

void solution(){
    fill(&visited[0][0], &visited[UBOUND][2], -1);
    bfs();
    cout << check();
}

int main(){
    input();
    solution();
}