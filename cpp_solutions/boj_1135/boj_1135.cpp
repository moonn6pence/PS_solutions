#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> child[50];

void input(){
    int p;
    cin >> N;

    cin >> p;

    for (int i = 1; i < N; i++) {
        cin >> p;
        child[p].push_back(i);
    }
}

int solve(int node){
    if(child[node].size() == 0) return 0;

    int ret = 0;

    vector<int> v;

    for(auto c : child[node]){
        v.push_back(solve(c));
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++) {
        ret = max(ret, v[i] + i + 1);
    }

    cout << node << " : " << ret << '\n';

    return ret;
}

void solution(){
    input();
    cout << solve(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}