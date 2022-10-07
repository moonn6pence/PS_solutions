#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000

using namespace std;

typedef pair<int, int> pii;

int N, e[MAX], m[MAX];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> m[i];

    for (int i = 0; i < N; i++)
        cin >> e[i];
}

int greedy(){
    vector<pii> order;
    for (int i = 0; i < N; i++)
        order.push_back({-e[i], m[i]});

    sort(order.begin(), order.end());

    int ret = 0, start = 0;

    for (int i = 0; i < N; i++){
        start += order[i].second;
        ret = max(ret, start - order[i].first);
    }

    return ret;
}

void solution(){
    int tc;
    cin >> tc;
    while(tc--){
        input();
        cout << greedy() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}