#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> psi;
int p, m;
vector<vector<psi>> rooms;
string result[2] = {"Waiting!", "Started!"};

void solution(){
    cin >> p >> m;
    int lv;
    string n;

    for (int i = 0; i < p; i++){
        cin >> lv >> n;

        if (rooms.empty()){
            vector<psi> room;
            room.push_back({n, lv});
            rooms.push_back(room);
        }
        else
        {
            bool flag = false;
            auto it = rooms.begin();

            while (it != rooms.end()){
                if ((*it)[0].second - 10 > lv || (*it)[0].second + 10 < lv || (*it).size() == m) {
                    it++;
                    continue;
                }
                flag = true;
                (*it).push_back({n, lv});
                break;
            }

            if (!flag){
                vector<psi> r;
                r.push_back({n, lv});
                rooms.push_back(r);
            }
        }
    }

    for(auto room : rooms){
        cout << result[(room.size() == m)] << '\n';
        sort(room.begin(), room.end());

        for(auto player : room){
            cout << player.second << ' ' << player.first << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}