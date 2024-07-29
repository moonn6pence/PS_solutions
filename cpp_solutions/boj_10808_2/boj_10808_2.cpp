#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> cnt;
    cnt.assign(26,0);
    string ss;
    cin >> ss;
    for(int i = 0; i < ss.length(); i++) cnt[ss[i] - 'a']++;
    for(auto& it : cnt) cout << it << ' ';
}