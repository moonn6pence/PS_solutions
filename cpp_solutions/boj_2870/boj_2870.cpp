#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool cmp(string a, string b){
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

vector<string> split(string s){
    regex re("[0-9]+");
    sregex_token_iterator it(s.begin(),s.end(), re, 0), end;

    return vector<string>(it, end);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M; cin >> M;

    vector<string> result;

    while (M--){

        string ss; cin >> ss;

        vector<string> v = split(ss);

        for(auto it : v) {
            if (it.find_first_not_of('0') == string::npos) result.push_back("0");
            else result.push_back(it.erase(0, it.find_first_not_of('0')));
        }
    }

    sort(result.begin(),result.end(),cmp);
    for(auto it : result) cout << it << '\n';
}