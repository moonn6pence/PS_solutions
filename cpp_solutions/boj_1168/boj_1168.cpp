#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> tree;

void input(){
    cin >> N >> K;
}

int makeTree(int node, int start, int end){
    if (start == end) return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

int deleteTree(int node, int start, int end, int idx){
    tree[node]--;

    if (start == end) return start;

    int mid = (start + end) / 2;

    if (tree[node * 2] >= idx ) return deleteTree(node * 2, start, mid, idx);
    return deleteTree(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
}

void solve(){
    int treeSize = 1 << ((int)ceil(log2(N)) + 1);
    tree.resize(treeSize);
    makeTree(1, 1, N);
    int len = N, order = K, num;

    cout << '<';
    while (len){
        num = deleteTree(1, 1, N, order);
        order = (order - 2 + K) % --len + 1;
        cout << num;
        if (len) cout << ", ";
    }
    cout << '>';
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