#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;
vector<int> lecture[10001];

void input(){
    cin >> N;

    int p, d;

    for (int i = 0; i < N; i++){
        cin >> p >> d;
        lecture[d].push_back(p);
    }
}

int solve(){
    int ret = 0;
    priority_queue<int> PQ;

    for (int i = 10000; i > 0; i--){
        for(auto& iter : lecture[i]) PQ.push(iter);
        
        if(!PQ.empty()){
            ret += PQ.top();
            PQ.pop();
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