#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M,cnt=0;
    cin >> N >> M;
    vector<int> v; v.resize(N);


    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int s = 0, e = N - 1;

    while(s < e){
        int sum = v[s] + v[e];

        if (sum > M) e--;
        else if (sum < M) s++;
        else {
            cnt++;
            s++; e--;
        }
    }

    cout << cnt;
}