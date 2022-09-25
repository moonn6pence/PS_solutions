#include <deque>
#include <iostream>
#define MAX 5000000

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

void solution(){
    int N, L;
    cin >> N >> L;
    deque<pli> deq;
    ll num;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        while(!deq.empty() && deq.front().second == i - L){
            deq.pop_front();
        }
        while(!deq.empty() && deq.back().first > num){
            deq.pop_back();
        }
        deq.push_back({num, i});
        cout << deq.front().first << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}