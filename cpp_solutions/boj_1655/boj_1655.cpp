#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, less<int>> lPQ;
priority_queue<int, vector<int>, greater<int>> rPQ;
int N, mid;

void input(){
    cin >> N;
}

void solve(){
    int cur;
    int lSize = 0, rSize = 0;

    cin >> mid;
    cout << mid << '\n';

    for (int i = 1; i < N; i++){
        cin >> cur;
        if (cur >= mid){
            rPQ.push(cur);
            rSize++;
            if ((rSize - lSize) > 1){
                lPQ.push(mid);
                lSize++;
                mid = rPQ.top();
                rPQ.pop();
                rSize--;
            }
        } else {
            lPQ.push(cur);
            lSize++;
            if (rSize < lSize){
                rPQ.push(mid);
                rSize++;
                mid = lPQ.top();
                lPQ.pop();
                lSize--;
            }
        }
        cout << mid << '\n';
    }
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}