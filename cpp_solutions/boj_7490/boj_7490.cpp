#include <iostream>
#include <algorithm>

using namespace std;
int N;

void input(){
    cin >> N;
}

void solve(int depth, int sign, int sum, int buff, string str){
    if(depth == N){
        sum += (buff * sign);
        if (sum == 0){
            cout << str << '\n';
        }
        return;
    }

    // depth, sign, sum, buff
    solve(depth + 1, sign, sum, buff * 10 + depth * sign, str + ' ' + char(depth + 1 + '0'));

    solve(depth + 1, 1, sum + buff * sign, depth * sign, str + '+' + char(depth + 1 + '0'));

    solve(depth + 1, -1, sum + buff * sign, depth * sign, str + '-' + char(depth + 1 + '0'));
}

void solution(){
    input();
    solve(1, 1, 0, 1, "1");
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