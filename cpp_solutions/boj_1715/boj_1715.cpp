#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N, sum = 0, chk = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() > 1) {
        int A = pq.top(); pq.pop();
        int B = pq.top(); pq.pop();
        sum += A + B;
        pq.push(A + B);
    }

    cout << sum;
}