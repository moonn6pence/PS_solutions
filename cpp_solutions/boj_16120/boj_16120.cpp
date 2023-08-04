#include <bits/stdc++.h>

using namespace std;

void solution(){
    string str; cin >> str;

    int cnt = 0, i = 0;

    while (i < str.length()){
        if (str[i] == 'P') {
            cnt++;
            i++;
        } else if(str[i] == 'A' && cnt > 1 && str[i+1] == 'P') {
            cnt--;
            i += 2;
        } else {
            cout << "NP";
            return;
        }
    }

    if(cnt <= 1) cout << "PPAP";
    else cout << "NP";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}