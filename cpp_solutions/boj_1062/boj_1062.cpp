#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<string> words;

void input(){
    cin >> N >> K;

    string str;
    for (int i = 0; i < N; i++){
        cin >> str;
        words.push_back(str);
    }
}

int countWord(int state){
    int ret = 0;

    for(string word : words){
        bool flag = false;

        for (int i = 0; i < word.length(); i++){
            if (state & (1 << (word[i] - 'a'))) continue;
            flag = true;
            break;
        }

        if (!flag) ret++;
    }
    return ret;
}

int solve(int state, int begin, int cnt){
    if (cnt == K) return countWord(state);

    int ret = 0;

    for (int i = begin; i < 26; i++){
        if (state & (1 << i)) continue;
        ret = max(ret, solve(state | (1 << i), i + 1, cnt + 1));
    }

    return ret;
}

void solution(){
    int state = 532741;
    input();
    if (K < 5) cout << 0;
    else if (K == 26) cout << N; 
    else cout << solve(state, 1, 5);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}