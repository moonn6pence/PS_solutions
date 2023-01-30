#include <iostream>
#include <string>

using namespace std;
int idx[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
string board;

string solve(){
    int cnt[2] = {0, 0};
    int win[2] = {0, 0};

    for (int i = 0; i < 8; i++){
        int same = 0;
        for (int j = 0; j < 2; j++) same += (board[idx[i][j]] == board[idx[i][j + 1]]);
        if (same == 2 && board[idx[i][0]] != '.') {
            win[board[idx[i][0]] == 'O']++;
        }
    }

    if (win[0] && win[1]) return "invalid";

    for (int i = 0; i < 3; i++){
        for (int j = i * 3; j < i * 3 + 3; j++){
            if (board[j] == '.') continue;
            cnt[board[j] == 'O']++;
        }
    }

    if (cnt[0] - cnt[1] < 0 || cnt[0] - cnt[1] > 1) return "invalid";

    if (!win[0] && !win[1] && cnt[0] < 5) return "invalid";

    if (win[0] && cnt[0] - cnt[1] != 1) return "invalid";

    if (win[1] && cnt[0] != cnt[1]) return "invalid";

    return "valid";
}

void solution(){
    while (true){
        cin >> board;
        if (board == "end") break;
        cout << solve() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}