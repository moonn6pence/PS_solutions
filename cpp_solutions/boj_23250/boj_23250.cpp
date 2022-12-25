#include <iostream>

using namespace std;
typedef unsigned long long int ulli;

int N;
ulli K, cur = 0;

void input(){
    cin >> N >> K;
}

ulli pow(int base, int exp){
    ulli tmp = 1;

    while(exp-- > 0){
        tmp = tmp << 1;
    }

    return tmp;
}

void hanoi(int n, int src, int via, int dest){
    if (n == 1){
        if(++cur == K) cout << src << ' ' << dest;
        exit(0);
    }

    if (K <= cur + pow(2, n - 1) - 1){
        hanoi(n - 1, src, dest, via);
    } else {
        cur += pow(2, n - 1) - 1;
    }

    if (++cur == K) {
        cout << src << ' ' << dest;
        exit(0);
    }

    hanoi(n - 1, via, src, dest);
}

void solution(){
    input();
    hanoi(N, 1, 2, 3);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}