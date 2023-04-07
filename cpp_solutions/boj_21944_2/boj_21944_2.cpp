#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> info; // l p g
const int INF = 987654321;
int N, M;
int lv[100001], tag[100001];
set<info> GASC[101], lvSet;
set<info, greater<info>> GDESC[101];
map<string, int> cmdSet = {{"recommend", 1}, {"recommend2", 2}, {"recommend3", 3}, {"add", 4}, {"solved", 5}};

void rcmd1(){
    int g, x, l, p;
    cin >> g >> x;

    if (x == 1) tie(l, p, g) = *GDESC[g].begin();
    else tie(l, p, g) = *GASC[g].begin();

    cout << p << '\n';
}

void rcmd2(){
    int x, l, p, g;
    cin >> x;

    if (x == 1) tie(l, p, g) = *lvSet.rbegin();
    else tie(l, p, g) = *lvSet.begin();

    cout << p << '\n';
}

void rcmd3(){
    int x, L;
    cin >> x >> L;

    if (x == 1){
        auto it = lvSet.upper_bound({L - 1, INF, INF});
        if (it == lvSet.end()){
            cout << -1 << '\n';
            return;
        }
        cout << get<1>(*it) << '\n';
    } else {
        auto it = lvSet.upper_bound({L, -INF, -INF});
        if (it == lvSet.begin()){
            cout << -1 << '\n';
            return;
        }
        cout << get<1>(*prev(it)) << '\n';
    }
}

void add(){
    int P, L, G;
    cin >> P >> L >> G;
    GDESC[G].insert({L, P, G});
    GASC[G].insert({L, P, G});
    lvSet.insert({L, P, G});
    lv[P] = L;
    tag[P] = G;
}

void solved(){
    int p;
    cin >> p;

    int g = tag[p], l = lv[p];

    GDESC[g].erase({l, p, g});
    GASC[g].erase({l, p, g});
    lvSet.erase({l, p, g});
    lv[p] = 0;
    tag[p] = 0;
}

void input(){
    string cmd;
    cin >> cmd;

    switch(cmdSet[cmd]){
        case 1:
            rcmd1();
            break;
        case 2:
            rcmd2();
            break;
        case 3:
            rcmd3();
            break;
        case 4:
            add();
            break;
        case 5:
            solved();
            break;
        default:
            break;
    }
}

void solution(){
    cin >> N;
    while (N--) add();

    cin >> M;
    while (M--) input();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}