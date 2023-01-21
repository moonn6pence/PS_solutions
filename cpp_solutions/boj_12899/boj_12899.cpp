#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2000000;
int N;
vector<int> tree;

void init(){
    int treeSize = 1 << ((int)ceil(log2(MAX_N)) + 1);
    tree.resize(treeSize);
}

void addTree(int node, int start, int end, int val){
    if (val < start || end < val) return;

    tree[node]++;

    if (start == end) return;

    int mid = (start + end) / 2;

    addTree(node * 2, start, mid, val);
    addTree(node * 2 + 1, mid + 1, end, val);
}

void deleteTree(int node, int start, int end, int val){
    tree[node]--;

    if (start == end) {
        cout << start << '\n';
        return;
    }

    int mid = (start + end) / 2;

    if (tree[node * 2] >= val) deleteTree(node * 2, start, mid, val);
    else deleteTree(node * 2 + 1, mid + 1, end, val - tree[node * 2]);
    
}

void input(){
    cin >> N;
    int T, num;

    while (N--){
        cin >> T >> num;
        if (T & 1) addTree(1, 1, MAX_N, num);
        else deleteTree(1, 1, MAX_N, num);
    }
}

void solution(){
    init();
    input();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}