#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N;
bool isPrime[40000];
vector<int> prime;
map<int, int> factor;

void init(){
    fill(&isPrime[0], &isPrime[40000], true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < 40000; i++){
        if (!isPrime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j < 40000; j += i){
            isPrime[j] = false;
        }
    }
}

ll input(){
    cin >> N;

    return N;
}

ll pow(ll n, ll r){
    ll ret = 1;

    while (r){
        if (r & 1) ret *= n;

        n *= n;
        r = r >> 1;
    }

    return ret;
}

ll getEulersPhi(ll a,ll n){
    return pow(a, n - 1) * (a - 1); 
}

void getFactor(int x){
    if (x == 1) return;

    for(auto i : prime){
        if (x % i == 0){
            factor[i]++;
            getFactor(x / i);
            return;
        }
    }
    
    if (x != 1) factor[x]++;
}

ll solve(){
    if (N == 1) return 0;
    
    factor.clear();
    getFactor(N);

    ll ret = 1;
    for(auto iter : factor) ret *= getEulersPhi(iter.first, iter.second);

    return ret;
}

void solution(){
    init();
    while(input()){
        cout << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}