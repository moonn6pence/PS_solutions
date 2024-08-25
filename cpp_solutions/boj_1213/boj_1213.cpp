#include <iostream>
#include <string>

using namespace std;

const string wa = "I'm Sorry Hansoo";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string ss;
    int cnt[26] = {0,}, odd = 0, odd_idx;

    cin >> ss;

    for(int i=0;i<ss.length();i++){
        cnt[ss[i] - 'A']++;
    }

    for(int i=0;i<26;i++){
        if (cnt[i] % 2 == 0) continue;

        odd++; odd_idx = i;
    }

    if ((ss.length() % 2 != 0 && odd == 1) || (ss.length() % 2 == 0 && odd == 0)) {
        if (odd == 1) cnt[odd_idx]--;

        for(int i=0;i<26;i++){
            for(int j=0;j*2<cnt[i];j++){
                cout << char('A' + i);
            }
        }

        if (odd == 1) cout << char('A'+odd_idx);

        for(int i=25;i>=0;i--){
            for(int j=0;j*2<cnt[i];j++){
                cout << char('A' + i);
            }
        }

        return 0;
    }
    
    cout << wa;

    return 0;
}