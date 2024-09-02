#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

const int INF = 2e9;

using namespace std;

struct node{
    int idx = INF;
    int cnt = 0;
};

bool cmp (pair<int,node> a, pair<int,node> b){
    if (a.second.cnt != b.second.cnt) return a.second.cnt > b.second.cnt;
    return a.second.idx < b.second.idx;
}

int main(){
    int N,C; cin >> N >> C;

    map<int, node> m;

    for(int i=0;i<N;i++){
        int x; cin >> x;

        m[x].cnt++;
        m[x].idx = min(i, m[x].idx);
    }

    vector<pair<int,node>> v(m.begin(),m.end());
    sort(v.begin(), v.end(), cmp);

    for(pair<int,node> it : v){
        if (it.first == 0) continue;

        while (it.second.cnt--) cout << it.first << ' ';
    }
}