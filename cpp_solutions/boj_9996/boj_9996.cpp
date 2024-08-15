#include <iostream>
#include <regex>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string ans[2] = {"NE", "DA"};
    int N; cin >> N;
    string p; cin >> p;

    p.insert(p.find_first_of("*"),".");

    regex re(p);
    string s;

    for(int i=0;i<N;i++) {
        cin >> s;
        cout << ans[regex_match(s,re)] << '\n';
    }
}