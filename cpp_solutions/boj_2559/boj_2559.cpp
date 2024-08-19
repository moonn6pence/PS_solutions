#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K,wnd=0,ans=-987654321;

    int temp[100000];

    cin >> N >> K;

    for(int i=0;i<N;i++) cin >> temp[i];

    for(int i=0;i<K;i++) wnd += temp[i];

    ans = wnd;

    for(int i=K;i<N;i++){
        wnd = temp[i] + wnd - temp[i-K];
        ans = max(ans, wnd);
    }

    cout << ans;
}