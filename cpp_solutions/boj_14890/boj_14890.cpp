#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, L;
int arr[100][100];

void input(){
    cin >> N >> L;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
}

int solve(){
    int ret = 0;

    for (int row = 0; row < N; row++){
        stack<pii> stack;
        int col = 0;
        while (col < N){
            int& H = arr[row][col++];
            if (stack.empty() || stack.top().first != H) stack.push({H, 1});
            else stack.top().second++;
        }

        pii prev = stack.top();
        stack.pop();

        while (!stack.empty()) {
            int H, cnt;
            tie(H, cnt) = stack.top();
            if (H == prev.first) {
                prev = stack.top();
                stack.pop();
            } else if (H + 1 == prev.first && cnt >= L){
                stack.top().second -= L;
                prev = stack.top();
                stack.pop();
            } else if (H - 1 == prev.first && prev.second >= L){
                prev = stack.top();
                stack.pop();
            } else break;
        }

        ret += stack.empty();
    }
    
    for (int col = 0; col < N; col++){
        stack<pii> stack;
        int row = 0;
        while (row < N){
            int& H = arr[row++][col];
            if (stack.empty() || stack.top().first != H) stack.push({H, 1});
            else stack.top().second++;
        }

        pii prev = stack.top();
        stack.pop();

        while (!stack.empty()) {
            int H, cnt;
            tie(H, cnt) = stack.top();
            if (H == prev.first) {
                prev = stack.top();
                stack.pop();
            } else if (H + 1 == prev.first && cnt >= L){
                stack.top().second -= L;
                prev = stack.top();
                stack.pop();
            } else if (H - 1 == prev.first && prev.second >= L){
                prev = stack.top();
                stack.pop();
            } else break;
        }

        ret += stack.empty();
    }

    return ret;
}

void solution(){
    input();
    cout << solve() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}