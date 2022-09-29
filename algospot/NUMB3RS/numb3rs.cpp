#include <iostream>
#include <cstring>

using namespace std;

int n, d, p, t;
double cache[51][101];
int graph[51][51], deg[51];

void input(){
    cin >> n >> d >> p;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
}

void init(){
    memset(cache, -1, sizeof(cache));
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            deg[i] += (graph[i][j] == 1 ? 1 : 0);
        }
    }
}

double search(int cur, int day){
    if(day == 0)
        return (cur == p ? 1.0 : 0.0);

    double &ret = cache[cur][day];

    if(ret > -0.5)
        return ret;

    ret = 0.0;

    for (int next = 0; next < n; next++){
        if(graph[cur][next])
            ret += search(next, day - 1) / deg[next];
    }

    return ret;
}

void output(){
    cin >> t;
    int q;
    for (int i = 0; i < t; i++){
        cin >> q;
        cout.precision(11);
        cout << search(q, d) << ' ';
    }
    cout << '\n';
}

void solution(){
    int tc;
    cin >> tc;
    while(tc--){
        input();
        init();
        output();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}