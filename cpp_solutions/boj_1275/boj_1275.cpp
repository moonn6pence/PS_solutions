#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, Q;
vector<int> v;
vector<ll> tree;

ll makeTree(int node, int start, int end) {
    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;
    return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

ll update(int node, int start, int end, int target, int diff) {
    if (target < start || end < target) return tree[node];
    if (start == end) return tree[node] = diff;

    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, target, diff) + update(node * 2 + 1, mid + 1, end, target, diff);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    v.resize(N);
    tree.resize(1 << ((int)ceil(log2(N)) + 1));

    for (int i = 0; i < N; i++) cin >> v[i];
    makeTree(1, 0, N - 1);

    int x, y, a, b;

    while(Q--) {
        cin >> x >> y >> a >> b;

        if (x > y) swap(x, y);

        cout << query(1, 0, N - 1, x - 1, y - 1) << '\n';
        update(1, 0, N - 1, a - 1, b);
    }
}