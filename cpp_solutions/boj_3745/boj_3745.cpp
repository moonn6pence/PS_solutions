#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int N, p[MAX], lis[MAX];

int getLIS(){
    lis[0] = p[0];

    int idx = 1;

    for (int i = 1; i < N; i++){
        if (lis[idx - 1] < p[i]) lis[idx++] = p[i];
        else lis[lower_bound(lis, lis+idx, p[i]) - lis] = p[i];
    }

    return idx;
}

void solution(){
    while(cin >> N){
        for (int i = 0; i < N; i++) cin >> p[i];
        fill(&lis[0], &lis[MAX], 0);
        cout << getLIS() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}