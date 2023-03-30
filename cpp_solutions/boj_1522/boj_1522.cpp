#include <bits/stdc++.h>

using namespace std;
map<string, int> visited;
string start;
regex re[4] = {regex("a+"), regex("a+b+a*"), regex("b+"), regex("b+a+b*")};

void input(){
    cin >> start;
}

bool check(string s){
    for (int i = 0; i < 4; i++){
        if (regex_match(s, re[i]))
            return true;
    }

    return false;
}

int BFS(){
    queue<string> order;
    order.push(start);
    visited[start] = 1;

    int ret = 2e9;

    while (!order.empty()){
        string cur = order.front();
        order.pop();

        if (check(cur)) return visited[cur] - 1;
        // if (check(cur)) {
        //     ret = min(ret, visited[cur] - 1);
        //     continue;
        // }

        for (int i = 0; i < cur.length(); i++){
            if (cur[i] == 'b') continue;

            for (int j = 0; j < cur.length(); j++){
                if (cur[j] == 'a') continue;

                string tmp = cur;
                char tmp_char = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tmp_char;

                if (visited[tmp] != 0 && visited[tmp] <= visited[cur] + 1) continue;
                // cout << cur << ' ' << tmp << '\n';

                order.push(tmp);
                visited[tmp] = visited[cur] + 1;
            }
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