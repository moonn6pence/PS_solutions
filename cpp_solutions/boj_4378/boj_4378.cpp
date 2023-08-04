#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> mapper;

void init(){

    string input = "1234567890-=WERTYUIOP[]SDFGHJKL;XCVBNM,./";
    string correction = "`1234567890-QWERTYUIOP[ASDFGHJKLZXCVBNM,.";

    for (int i = 0; i < input.length(); i++){
        mapper[input[i]] = correction[i];
    }

    mapper['\\'] = ']';
    mapper['\''] = ';';
}

void solution(){

    init();
    string line, answer;

    while (getline(cin, line)){
        answer = "";

        for(char key : line){
            answer += key != ' ' ? mapper[key] : ' ';
        }

        cout << answer << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}