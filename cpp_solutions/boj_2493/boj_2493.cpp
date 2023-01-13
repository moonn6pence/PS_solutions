#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int N;
int arr[500000];
int ans[500000];

void input(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
}

void solve(){
    stack<pii> stack;
    stack.push({N, arr[N]});
    arr[0] = INF;
    int idx = N - 1;

    while (!stack.empty()){
        if (stack.top().first == -1) break;

        if (stack.top().second < arr[idx]){
            while(!stack.empty() && stack.top().second < arr[idx]){
                ans[stack.top().first] = idx;
                stack.pop();
            }
        }
        stack.push({idx, arr[idx]});
        idx--;
    }
}

void output(){
    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
}

void solution(){
    input();
    solve();
    output();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}