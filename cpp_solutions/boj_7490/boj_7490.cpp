#include <iostream>
#include <algorithm>

using namespace std;
int N;
int visited[10];

void input(){
    cin >> N;
}

int calculate(int depth, int sum){
    if(visited[depth] == 1){
        return sum + depth;
    }

    if(visited[depth] == 2){
        return sum - depth;
    }

    if(visited[depth] == 3){
        return sum + depth * 10;
    }

    return 0;
}

string getOperator(int depth){
    if(depth == N) return "";

    if(visited[depth] == 1) return "+";

    if (visited[depth] == 2) return "-";

    return " ";
}

void solve(int depth, int sum, int buff){
    if(depth == N){
        if (sum + buff == 0){
            cout << "1";
            for (int i = 1; i < N; i++){
                cout << getOperator(i) << i + 1;
            }
            cout << '\n';
        }
        return;
    }

    int newBuff;
    visited[depth] = 0;
    if(buff >= 0)
        newBuff = buff * 10 + depth + 1;
    else
        newBuff = buff * 10 - depth - 1;
    solve(depth + 1, sum, newBuff);

    visited[depth] = 1;
    solve(depth + 1, sum + buff, depth + 1);

    visited[depth] = 2;
    solve(depth + 1, sum + buff, -depth - 1);
}

void solution(){
    input();
    visited[0] = 1;
    solve(1, 0, 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        solution();
        cout << '\n';
    }

    return 0;
}