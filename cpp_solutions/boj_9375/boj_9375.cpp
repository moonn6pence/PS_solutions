#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int T; cin >> T;

    while(T--){
        unordered_map<string, int> v;

        int n, ans = 1; cin >> n;

        for(int i=0;i<n;i++){
            string c,t;
            cin >> c >> t;
            v[t]++;
        }

        for(pair<string, int> it : v) ans *= (it.second + 1);
        cout << (ans - 1) << '\n';
    }
}