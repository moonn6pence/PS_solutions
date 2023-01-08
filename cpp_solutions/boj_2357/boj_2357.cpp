#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9 + 1;
int N, M;
vector<int> num;
vector<int> minSeg;
vector<int> maxSeg;

void input(){
    cin >> N >> M;

    int temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        num.push_back(temp);
    }
}

int makeMinSegmentTree(int node, int start, int end){
    if (start == end) return minSeg[node] = num[start];

    int mid = (start + end) / 2;
    return minSeg[node] = min(makeMinSegmentTree(node * 2, start, mid), makeMinSegmentTree(node * 2 + 1, mid + 1, end));
}

int makeMaxSegmentTree(int node, int start, int end){
    if (start == end) return maxSeg[node] = num[start];

    int mid = (start + end) / 2;
    return maxSeg[node] = max(makeMaxSegmentTree(node * 2, start, mid), makeMaxSegmentTree(node * 2 + 1, mid + 1, end));
}

int queryMin(int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return INF;

    if (left <= start && end <= right)
        return minSeg[node];

    int mid = (start + end) / 2;
    return min(queryMin(node * 2, start, mid, left, right), queryMin(node * 2 + 1, mid + 1, end, left, right));
}

int queryMax(int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return -INF;

    if (left <= start && end <= right)
        return maxSeg[node];

    int mid = (start + end) / 2;
    return max(queryMax(node * 2, start, mid, left, right), queryMax(node * 2 + 1, mid + 1, end, left, right));
}

void solve(){
    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h + 1));
    minSeg.resize(treeSize);
    maxSeg.resize(treeSize);

    makeMinSegmentTree(1, 0, N - 1);
    makeMaxSegmentTree(1, 0, N - 1);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << queryMin(1, 0, N - 1, a - 1, b - 1) << ' ';
        cout << queryMax(1, 0, N - 1, a - 1, b - 1) << '\n';
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