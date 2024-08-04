#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string drop_out = "PREDAJA";
    vector<int> cnt(26,0);
    bool b = false;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string ss;
        cin >> ss;

        cnt[ss[0] - 'a']++;
    }

    for(int i=0;i<26;i++){
        if (cnt[i]>4) {
            cout << char('a' + i);
            b = true;
        }
    }

    if (!b) cout << drop_out;
}