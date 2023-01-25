#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a,b);
    cout << (b * b - a * a + a + b) / 2 << '\n';
}