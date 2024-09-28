#include <iostream>
#include <vector>

using namespace std;
vector<int> root;
vector<int> child[51];

void input(){
    int N, del; cin >> N;

    vector<int> tmp; tmp.resize(N);

    for(int i=0;i<N;i++) cin >> tmp[i];

    cin >> del;

    for(int i=0;i<N;i++) {
        if (i == del) continue;

        if (tmp[i] == -1) root.push_back(i);
        else child[tmp[i]].push_back(i);
    }
}

int dfs(int cur){
    if (child[cur].empty()) return 1;

    int cnt = 0;

    for(int c : child[cur]) cnt += dfs(c);

    return cnt;
}

void solution(){

    input();
    int ret = 0;
    for(int node : root) ret += dfs(node);
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution();
}