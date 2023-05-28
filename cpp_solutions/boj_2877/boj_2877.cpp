#include <bits/stdc++.h>

using namespace std;

void solution(){
    string str;
    char ch[2] = {'4','7'};
    int K;
    cin >> K;
    K++;

    for (int i = 0; i < 30; i++ ){
        if ((1 << i) > K) break;

        str += ch[(K & (1 << i)) != 0];
    }

    reverse(str.begin(), str.end());
    cout << str.substr(1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}