#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n, d;
int home[100000], office[100000];
vector<pii> vec;

void input(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> home[i] >> office[i];
        int start = min(home[i],office[i]);
        int end = max(home[i], office[i]);
        vec.push_back({start, end});
    }
    sort(vec.begin(), vec.end());

    cin >> d;
}

int solve(){
    int ret = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = n - 1; i >= 0; i--){
        if(vec[i].second - vec[i].first > d) continue;
        pq.push(vec[i].second);

        while(!pq.empty() && pq.top() > vec[i].first + d) pq.pop();

        ret = max<int>(ret, pq.size());
    }

    return ret;
}

void solution(){
    input();
    cout << solve();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}