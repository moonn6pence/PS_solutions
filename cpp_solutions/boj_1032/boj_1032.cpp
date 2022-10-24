#include <iostream>
#include <string>

using namespace std;
int N,len;
string files[50];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> files[i];
    }
    len = files[0].length();
}

void solve(){
    if (N == 1){
        cout << files[0] << '\n';
        return;
    }

    string search;
    search = files[0];

    for (int i = 1; i < N; i++){
        for (int j = 0; j < len; j++){
            if(search[j] == '?') continue;
            if(search[j] != files[i][j])
                search[j] = '?';
        }
    }

    cout << search << '\n';
}

void solution(){
    input();
    solve();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}