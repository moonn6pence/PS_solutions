#include <bits/stdc++.h>

using namespace std;
int parent[1000001];

int find(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) _union(a, b);
        else cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
    }
}