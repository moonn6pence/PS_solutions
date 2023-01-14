#include <bits/stdc++.h>

using namespace std;
int N;
int A[100001];
vector<int> tree;

void input(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
}

int smaller(int leftIdx, int rightIdx){
    if (leftIdx == -1) return rightIdx;
    if (rightIdx == -1) return leftIdx;

    return A[leftIdx] <= A[rightIdx] ? leftIdx : rightIdx;
}

int makeTree(int node, int start, int end){
    if (start == end) return tree[node] = start;

    int mid = (start + end) / 2;

    int leftIdx = makeTree(node * 2, start, mid);
    int rightIdx = makeTree(node * 2 + 1, mid + 1, end);

    return tree[node] = smaller(leftIdx, rightIdx);
}

int query(int node, int start, int end, int left, int right){
    if (left > end || right < start) return -1;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int leftIdx = query(node * 2, start, mid, left, right);
    int rightIdx = query(node * 2 + 1, mid + 1, end, left, right);

    return smaller(leftIdx, rightIdx);
}

int updateTree(int node, int start, int end, int idx){
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node];

    int mid = (start + end) / 2;
    int leftIdx = updateTree(node * 2, start, mid, idx);
    int rightIdx = updateTree(node * 2 + 1, mid + 1, end, idx);

    return tree[node] = smaller(leftIdx, rightIdx);
}

void solution(){
    input();
    int M, op, i, j, treeSize = 1 << ((int)ceil(log2(N)) + 1);
    tree.resize(treeSize);

    makeTree(1, 1, N);

    cin >> M;
    while (M--){
        cin >> op >> i >> j;
        if (op == 1) {
            A[i] = j;
            updateTree(1, 1, N, i);
        }
        else cout << query(1, 1, N, i, j) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}