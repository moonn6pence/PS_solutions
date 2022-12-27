#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
int N;
int seq[100000];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> seq[i];
    }
}

ll solve(){
    int lo = 0, hi = 0;
    ll ans = 0;
    set<int> window;
    window.insert(seq[0]);

    while (lo < N && hi < N){
        if (hi == N - 1 || window.find(seq[hi + 1]) != window.end()){
            ans += hi - lo + 1;
            window.erase(window.find(seq[lo++]));
        } else{
            window.insert(seq[++hi]);
        }
    }

    return ans;
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