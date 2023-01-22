#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

bool cmp(pii p1, pii p2){
    if (p1.second == p2.second)
        return p1.first < p2.first;

    return p1.second < p2.second;
}

vector<pii> makeVector(vector<vector<int>> routes){
    vector<pii> ret;
    for (auto &iter : routes){
        ret.push_back({iter[0], iter[1]});
    }

    sort(ret.begin(), ret.end(), cmp);

    return ret;
}

int solve(vector<pii> routes){
    int ret = 0, cur = -40000;

    for (auto& route : routes){
        if (cur < route.first){
            ret++;
            cur = route.second;
        }
    }

    return ret;
}

int solution(vector<vector<int>> routes) {
    int answer = solve(makeVector(routes));
    return answer;
}