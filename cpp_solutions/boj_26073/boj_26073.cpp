#include <bits/stdc++.h>

using namespace std;
string output[2] = {"Gave up", "Ta-da"};

int GCD(int a, int b){
    if (b == 0) return a;
    return GCD(b, a % b);
}

bool solve(vector<int>& v, int x, int y){
    sort(v.begin(), v.end());
    if (v[0] == 1) return 1;

    int len = v.size() - 1;
    int gcd = v[0], i = 1;

    while (len--){
        gcd = GCD(gcd, v[i++]);
    }

    return (x % gcd == 0) && (y % gcd == 0);
}

void solution(){
    int x, y, n, N, d;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x >> y >> n;
        vector<int> v;

        while (n--){
            cin >> d;
            v.push_back(d);
        }

        cout << output[solve(v, x, y)] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}