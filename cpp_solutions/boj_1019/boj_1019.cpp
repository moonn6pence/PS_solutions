#include <iostream>
#include <algorithm>

using namespace std;

int N;
int lookUp[10] = {0,};

void input(){
    cin >> N;
}

void solve(){
    for (int i = 0; i < 10; i++){
        int radix = 1;
        int nextRadix = radix * 10;
        while (radix <= N){
            if(nextRadix > N && i == 0)
                break;

            int tmp = int(N / (nextRadix) - (i == 0) - (int(N % (nextRadix) / radix) < i)) * radix;
            tmp += (int(N % (nextRadix) / radix) != i) ? radix: N % radix + 1;

            lookUp[i] += tmp;

            radix = nextRadix;
            nextRadix *= 10;
        }
    }
}

void output(){
    for(auto iter : lookUp){
        cout << iter << ' ';
    }
}

void solution(){
    input();
    solve();
    output();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}