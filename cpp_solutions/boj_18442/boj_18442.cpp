#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int V, P;
ll L, sum = 2e13;
ll village[20];
bool visited[20] = {false,};
vector<ll> postOffice;

void input(){
    cin >> V >> P >> L;

    for (int i = 0; i < V; i++) cin >> village[i];
}

ll calculateDistance(ll x, ll y){
    return min(abs(x - y), L - abs(x - y));
}

ll getDistances(vector<ll> office){
    ll tmpSum = 0;
    for (int i = 0; i < V; i++){
        ll tmp = 1e12;
        for (auto iter : office){
            tmp = min(tmp, calculateDistance(village[i], iter));
        }
        tmpSum += tmp;
    }

    return tmpSum;
}

void backtracking(int depth, int last,vector<ll> office){
    if(depth == P){
        ll tmpSum = getDistances(office);

        if (sum > tmpSum){
            sum = tmpSum;
            postOffice.assign(office.begin(), office.end());
        }
    }

    for (int i = last + 1; i < V; i++){
        if(!visited[i]) {
            visited[i] = true;
            office.push_back(village[i]);
            backtracking(depth + 1, i, office);
            visited[i] = false;
            office.pop_back();
        }
    }
}


void solution(){
    vector<ll> office;
    input();
    backtracking(0, -1, office);
    cout << sum << '\n';
    for(auto iter : postOffice)
        cout << iter << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}