#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> A;

void input(){
    cin >> N >> M;
    int i = N, tmp;
    while (i--){
        cin >> tmp;
        A.push_back(tmp);
    }
}

int search(){
    int lo = 0, hi = 1;

    int ansLo = 0, ansHi = N - 1;

    while (lo <= hi && hi < N){
        if(hi != lo && A[hi] - A[lo] <= A[ansHi] - A[ansLo] && A[hi] - A[lo] >= M){
            ansLo = lo;
            ansHi = hi;
        }

        int tmp = A[hi] - A[lo];

        if (tmp == M)
            break;
        if (tmp < M)
            hi += 1;
        else
            lo += 1;
    }

    return A[ansHi] - A[ansLo];
}

void solution(){
    input();
    sort(A.begin(), A.end());
    cout << search() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}