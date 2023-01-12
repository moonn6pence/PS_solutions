#include <bits/stdc++.h>

using namespace std;
int arr[100][100];

void input(){
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            cin >> arr[i][j];
        }
    }
}

int solve(){
    int ret = -2e9;

    for (int i = 0; i < 100; i++){
        int tmp1 = 0, tmp2 = 0;
        for (int j = 0; j < 100; j++){
            tmp1 += arr[i][j];
            tmp2 += arr[j][i];
        }
        ret = max(ret, tmp1);
        ret = max(ret, tmp2);
    }

    int tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < 100; i++){
        tmp1 += arr[i][i];
        tmp2 += arr[i][99 - i];
    }
    ret = max(ret, tmp1);
    ret = max(ret, tmp2);

    return ret;
}

void solution(){
    int tc = 10, i;
    
    while (tc--){
        cin >> i;
        input();
        cout << '#' << i << ' ' << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}