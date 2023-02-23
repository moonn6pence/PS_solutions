#include <iostream>
#include <string>
#include <regex>

using namespace std;
regex re[4] = {regex("[a-z]"),regex("[A-Z]"),regex("[0-9]"),regex(" ")};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    auto end = sregex_iterator();

    while (getline(cin, str)) {
        for (int i = 0; i < 4; i++){
            auto iter = sregex_iterator(str.begin(), str.end(), re[i]);
            cout << distance(iter, end) << ' ';
        }
        cout << '\n';
    }
}