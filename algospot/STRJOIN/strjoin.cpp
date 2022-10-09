#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> str;

void input(){
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        str.push_back(tmp);
    }
}

int greedy(const vector<int>& lengths){
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
        pq.push(lengths[i]);
    int ret = 0;

    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        ret += min1 + min2;
        pq.push(min1 + min2);
    }

    return ret;
}

void solution(){
    int tc;
    cin >> tc;

    while(tc--){
        str.clear();
        input();
        cout << greedy(str) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}