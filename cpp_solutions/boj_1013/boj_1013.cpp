#include <iostream>
#include <string>
#include <regex>

using namespace std;
string radio;

void input(){
    cin >> radio;
}

string solve(){
    regex re("(100+1+|01)+");
    if(regex_match(radio, re))
        return "YES";
    return "NO";
}

void solution(){
    int tc;
    cin >> tc;
    while(tc--){
        input();
        cout << solve() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution();
}