#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string text;
int answer = 0;

void input(){
    cin >> text;
}

int getPi(string pattern){
    int patSize = pattern.size();
    vector<int> table(patSize, 0);

    int j = 0;
    for (int i = 1; i < patSize; i++){
        while (j > 0 && pattern[i] != pattern[j]){
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }

    return *max_element(table.begin(),table.end());
}

int solve(){
    for (int i = 0; i < text.size(); i++){
        string pattern = text.substr(i);
        answer = max(answer, getPi(pattern));
    }

    return answer;
}

void solution(){
    input();
    cout << solve();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();
}