#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
double cache[1001][2001];

void init(){
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 2001; j++){
            cache[i][j] = -1;
        }
    }
}

void input(){
    cin >> n >> m;
}

double climb(int day, int climbed){
    if (day == m)
        return climbed >= n ? 1 : 0;

    double &ret = cache[day][climbed];

    if(ret != -1)
        return ret;

    return ret = 0.25 * climb(day + 1, climbed + 1) + 0.75 * climb(day + 1, climbed + 2);
}

void solution(){
    int tc;
    cin >> tc;

    while(tc--){
        init();
        input();
        cout.precision(11);
        cout << climb(0, 0) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}