#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int N, C, M;
vector<tiii> inputs;

void solution(){
    cin >> N >> C >> M;

    int from, to, box, cur = 0, delivered = 0;
    vector<int> truck(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> from >> to >> box;
        inputs.push_back({from, to, box});
    }

    sort(inputs.begin(), inputs.end(), [](tiii a, tiii b){return get<1>(a) < get<1>(b);});

    for(auto it : inputs){
        tie(from, to, box) = it;
        int rangeMax = 0, capacity;

        rangeMax = *max_element(truck.begin() + from, truck.begin() + to);
        capacity = (rangeMax + box <= C ? box : C - rangeMax);

        auto via = truck.begin() + from;
        while (via != truck.begin() + to) {
            *via += capacity;
            via++;
        }

        delivered += capacity;
    }

    cout << delivered;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}