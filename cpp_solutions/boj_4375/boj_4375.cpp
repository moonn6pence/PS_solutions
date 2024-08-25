#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    unordered_map<int, int> m;
    while(cin >> n){
        if (m.find(n) != m.end()) {
            cout << m[n];
            break;
        }

        int digit = 1, base = 1;
        while (1) {
            if (base % n == 0) break;
            digit++;
            base = (base * 10 + 1) % n;
        }
        m[n] = digit;
        cout << digit << '\n';
    }
}