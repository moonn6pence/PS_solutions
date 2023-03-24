#include <bits/stdc++.h>

using namespace std;
int S, E, Q;
map<string, bool> startLog;
map<string, bool> endLog;

int parseTime(string* s){
    istringstream iss(*s);
    string buf;
    int ret = 0;
    bool flag = true;

    while (getline(iss, buf, ':')){
        ret += stoi(buf);
        if (flag){
            ret *= 60;
            flag = false;
        }
    }

    return ret;
}

void parseInfo(string* s){
    istringstream iss(*s);
    string buf;
    int sec;
    vector<string> ret;

    while (getline(iss, buf, ' ')){
        ret.push_back(buf);
    }

    sec = parseTime(&ret[0]);

    if (sec <= S){
        startLog[ret[1]] = true;
    } else if(E <= sec && sec <= Q){
        endLog[ret[1]] = true;
    }
}

void input(){
    string tmp1, tmp2, tmp3;

    cin >> tmp1 >> tmp2 >> tmp3;

    S = parseTime(&tmp1);
    E = parseTime(&tmp2);
    Q = parseTime(&tmp3);

    getline(cin, tmp1);

    while (getline(cin, tmp1)){
        parseInfo(&tmp1);
    }
}

int solve(){
    int ret = 0;

    for(auto [key,value] : startLog){
        if(startLog[key] && endLog[key]) ret++;
    }

    return ret;
}

void solution(){
    input();
    cout << solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}