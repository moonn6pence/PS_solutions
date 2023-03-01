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

void makeStack(stack<pii>& stack, int idx, bool isRow){
    int x = 0;
    while (x < N){
        int& H = isRow ? arr[idx][x++] : arr[x++][idx];
        if (stack.empty() || stack.top().first != H) stack.push({H, 1});
        else stack.top().second++;
    }
}

bool checkStack(stack<pii>& stack){
    pii prev = stack.top();
    stack.pop();

    while (!stack.empty()) {
        int H, cnt;
        tie(H, cnt) = stack.top();
        
        if (H + 1 == prev.first && cnt >= L) stack.top().second -= L;
        else if (H - 1 != prev.first || prev.second < L) return false;
        
        prev = stack.top();
        stack.pop();
    }
    
    return true;
}

int solve(){
    int ret = 0;

    for (int i = 0; i < N; i++){
        stack<pii> rowStack, colStack;
        makeStack(rowStack, i, true);
        makeStack(colStack, i, false);
        ret += checkStack(rowStack) + checkStack(colStack);
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