#include <iostream>

using namespace std;

int main(){
    int N, M, J; cin >> N >> M >> J;

    int l = 1, r = M, dist = 0;

    while (J--){
        int apple, tmp = 0; cin >> apple;

        if (apple < l) {
            tmp = l - apple;
            l -= tmp; r -= tmp;
        } else if (apple > r) {
            tmp = apple - r;
            l += tmp; r += tmp;
        }
        dist += tmp;
    }

    cout << dist;
}