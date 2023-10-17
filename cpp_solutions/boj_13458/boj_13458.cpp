#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int B, C, D, N;
    vector<int> A;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> B >> C;

    long long sum = N;
    for (int i = 0; i < N; i++) {
        D = A[i] - B;
        sum += D > 0 ? D / C + (D % C != 0) : 0;
    }
    cout << sum;
}