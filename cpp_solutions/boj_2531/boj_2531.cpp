#include <iostream>
#include <queue>

using namespace std;

int N, d, k, c;
int sushi[33000];
int ate[3001] = {0,};

void input(){
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++){
        cin >> sushi[i];
        if (i < k - 1) sushi[i + N] = sushi[i];
    }
}

int solve(){
    queue<int> cur;
    int ret = 0, tmp = 0;

    for (int i = 0; i < k; i++){
        cur.push(sushi[i]);
        if(!ate[sushi[i]]){
            tmp++;
        }
        ate[sushi[i]]++;
    }
    ret = max(ret, tmp);
    if(!ate[c]) ret++;


    for (int i = k; i < N + k - 1; i++){
        int front = cur.front();
        ate[front]--;
        if(!ate[front]) tmp--;
        cur.pop();

        cur.push(sushi[i]);
        int back = cur.back();
        if(!ate[back]) tmp++;
        ate[back]++;

        ret = max(ret, tmp + (!ate[c]));
        cout << i << " "  << back <<" " << tmp << '\n';
    }

    return ret;
}

void solution(){
    input();
    cout << solve();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}