#include <bits/stdc++.h>

using namespace std;
int n,m;
int name[1000], cache[1000][1001];

void input(){
    cin >> n >> m;
    m++;

    for (int i = 0; i < n; i++){
        cin >> name[i];
        name[i]++;
    }
}

int solve(int idx, int len){
    if(idx >= n) return 0;

    int &ret = cache[idx][len];

    if (ret != -1) return ret;

    ret = (m - len) * (m - len) + solve(idx + 1, name[idx]);

    if (len + name[idx] <= m) ret = min(ret, solve(idx + 1, len + name[idx]));

    return ret;
}

void solution(){
    input();
    fill(&cache[0][0], &cache[999][1001], -1);
    cout << solve(0, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}