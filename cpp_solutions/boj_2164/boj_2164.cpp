#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, ret = 0;
    cin >> N;
    if (!(N&(N-1))) ret = N;
    else for (int i = 2; i <= N; i++) ret =(ret + 2) % i;
    cout << ret;
}