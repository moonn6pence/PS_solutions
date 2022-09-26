#include <iostream>
#include <memory.h>

using namespace std;
int tri[100][100];
int sumCache[100][100];
int pathCache[100][100];
int n;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i + 1; j++){
            cin >> tri[i][j];
        }
    }
}

int path(int y, int x){
    if(y == n-1) return tri[y][x];

    int &ret = sumCache[y][x];

    if(ret != -1) return ret;

    ret = tri[y][x] + max(path(y + 1, x), path(y + 1, x + 1));

    return ret;
}

int count(int y, int x){
    if(y == n-1) return 1;

    int &ret = pathCache[y][x];

    if(ret != -1) return ret;

    ret = 0;
    if(path(y+1,x) >= path(y+1,x+1)) ret += count(y + 1, x);
    if(path(y+1,x) <= path(y+1,x+1)) ret += count(y + 1, x + 1);

    return ret;
}

void solution(){
    int tc;
    cin >> tc;
    while(tc--){
        memset(pathCache, -1, sizeof(pathCache));
        memset(sumCache, -1, sizeof(sumCache));
        input();
        path(0, 0);
        count(0, 0);
        cout << pathCache[0][0] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}