#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const string ac = "is acceptable.\n", wa = "is not acceptable.\n";
    string s;
    char vowel[5] = {'a','e','i','o','u'};
    bool is_vowel[26];
    fill(is_vowel, is_vowel+26, false);
    for(char c : vowel) is_vowel[c-'a'] = true;

    int az[26];

    while(1){
        cin >> s;

        if (s=="end") break;

        bool ret = true;
        int v_tmp = 0, c_tmp = 0, v = 0;
        char prev = '\0';
        fill(az, az+26, 0);

        for(char c : s) {

            if (c != prev && prev != '\0') az[prev-'a'] = 0;
            az[c-'a']++;

            if (c != 'e' && c != 'o' && az[c-'a'] >= 2) {
                ret = false;
                break;
            }
            prev = c;

            if (is_vowel[c-'a']) {
                v++;
                c_tmp=0;
                v_tmp++;
                if (v_tmp == 3) {
                    ret = false;
                    break;
                }
            } else {
                v_tmp=0;
                c_tmp++;
                if (c_tmp == 3) {
                    ret = false;
                    break;
                }
            }
        }
        cout << "<" << s << "> ";
        if (!ret || v == 0) cout << wa;
        else cout << ac;
    }
}