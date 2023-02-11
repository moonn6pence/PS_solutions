#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int r, c, k, rowSize = 3, colSize = 3;
int A[100][100];

void input(){
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) cin >> A[i][j];
    }
}

void Csort(){
    map<int, int> num[rowSize];
    vector<pii> nums[rowSize];
    int newColSize = 0;

    for (int j = 0; j < rowSize; j++){
        for (int i = 0; i < colSize; i++){
            if (A[i][j] == 0) continue;
            num[j][A[i][j]]++;
        }

        for(auto& iter : num[j]) nums[j].push_back({iter.second, iter.first});

        sort(nums[j].begin(), nums[j].end());
        newColSize = max(newColSize, (int)nums[j].size() * 2);
    }

    colSize = newColSize;

    for (int j = 0; j < rowSize; j++){
        int i = 0;

        while (i < nums[j].size()){
            A[i * 2][j] = nums[j][i].second;
            A[i++ * 2 + 1][j] = nums[j][i].first;
        }

        for (i = i * 2; i < colSize; i++) A[i][j] = 0;
    }
}

void Rsort(){
    map<int, int> num[colSize];
    vector<pii> nums[colSize];
    int newRowSize = 0;

    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            if (A[i][j] == 0) continue;
            num[i][A[i][j]]++;
        }

        for(auto& iter:num[i]) nums[i].push_back({iter.second, iter.first});

        sort(nums[i].begin(), nums[i].end());
        newRowSize = max(newRowSize, (int)nums[i].size() * 2);
    }

    rowSize = newRowSize;

    for (int i = 0; i < colSize; i++){
        int j = 0;

        while (j < nums[i].size()){
            A[i][j * 2] = nums[i][j].second;
            A[i][j++ * 2 + 1] = nums[i][j].first;
        }

        for (j = j * 2; j < rowSize; j++) A[i][j] = 0;
    }
}

int solve(){
    int t = -1;

    while (++t <= 100){
        if (A[r-1][c-1] == k) return t;

        if (rowSize > colSize) Csort();
        else Rsort();
    }

    return -1;
}

void solution(){
    input();
    cout << solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}