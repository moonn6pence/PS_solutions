#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, K;
int order[100];
set<int> cnt[101];
set<int> tab;

void input(){
    cin >> N >> K;

    for (int i = 0; i < K; i++){
        cin >> order[i];
        cnt[order[i]].insert(i);
    }
}

int solve(){
    int ret = 0;

    if (N >= K) return ret;

    for (int i = 0; i < K; i++){
        auto iter = tab.find(order[i]);
        if (iter != tab.end()){
            cnt[order[i]].erase(i);
        } else {
            if (tab.size() == N){
                ret++;
                int mx, mxIdx = -1;
                for (auto cur : tab){
                    if (cnt[cur].empty()){
                        mx = cur;
                        break;
                    }
                    mxIdx = max(mxIdx, *cnt[cur].begin());
                    mx = order[mxIdx];
                }
                tab.erase(mx);
            }
            tab.insert(order[i]);
            cnt[order[i]].erase(cnt[order[i]].begin());
        }
    }

    return ret;
}

void solution(){
    input();
    cout << solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}