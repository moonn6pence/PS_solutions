#include <iostream>

using namespace std;
typedef long long ll;
const int MOD = 1000000;
ll N;

void input(){
    cin >> N;
}

void multiply(ll F[2][2], ll B[2][2]){

    ll a = (F[0][0] * B[0][0] % MOD + F[0][1] * B[1][0] % MOD) % MOD;
    ll b = (F[0][0] * B[0][1] % MOD + F[0][1] * B[1][1] % MOD) % MOD;
    ll c = (F[1][0] * B[0][0] % MOD + F[1][1] * B[1][0] % MOD) % MOD;
    ll d = (F[1][0] * B[0][1] % MOD + F[1][1] * B[1][1] % MOD) % MOD;

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

ll power(ll exp){
    if (exp == 0) return 1;

    ll pivot[2][2] = {{1, 1}, {1, 0}};
    ll ret[2][2] = {{1, 0}, {0, 1}};

    while (exp){
        if (exp & 1){
            multiply(ret, pivot);
        }

        multiply(pivot, pivot);
        exp /= 2;
    }

    return ret[0][0];
}

void solution(){
    input();
    cout << power(N - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

solution();
}