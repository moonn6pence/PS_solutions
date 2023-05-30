#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> psi;
int N, K;
string start, answer = "12345678";
map<string, int> visited;

void input(){
    string s;

    cin >> N >> K;

    for (int i = 0; i < N; i++){
        cin >> s;
        start += s;
    }

    answer = start;
    sort(answer.begin(), answer.end());
}

string flip(string& str, int offset){
    string ret = str;

    for (int i = 0, j = K - 1; i < K / 2; i++, j--){
        char tmp = ret[offset + i];
        ret[offset + i] = ret[offset + j];
        ret[offset + j] = tmp;
    }

    return ret;
}

int BFS(){

    queue<psi> order;
    order.push({start, 1});
    visited[start] = 1;

    string cur;
    int cost;

    while(!order.empty()){
        tie(cur, cost) = order.front();
        order.pop();

        if (cur == answer) return cost - 1;

        for (int i = 0; i <= N - K; i++){
            string fliped = flip(cur, i);
            if (visited[fliped]) continue;

            visited[fliped] = cost + 1;
            order.push({fliped, cost + 1});
        }
    }

    return -1;
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