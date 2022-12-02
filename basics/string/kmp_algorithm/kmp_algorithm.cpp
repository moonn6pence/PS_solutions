#include <iostream>
#include <vector>

using namespace std;

string text,pattern;

void input(){
    cout << "text> ";
    cin >> text;
    cout << "pattern> ";
    cin >> pattern;
}

// prefix, suffix 일치 숫자 테이블 생성
vector<int> makeTable(string pattern){
    int pSize = pattern.size();
    vector<int> table(pSize, 0);
    int j = 0;
    for (int i = 1; i < pSize; i++){
        while (j > 0 && pattern[i] != pattern[j]){
            j = table[j - 1];
        }
        
        if (pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }

    return table;
}

vector<int> kmp(string text, string pattern){
    vector<int> table = makeTable(pattern);
    vector<int> findAt;

    int textSize = text.size();
    int patSize = pattern.size();

    int j = 0;

    for (int i = 0; i < textSize; i++){

        while (j > 0 && text[i] != pattern[j]){
            j = table[j - 1];
        }

        if (text[i] == pattern[j]){
            if (j == patSize - 1){
                findAt.push_back(i - patSize + 1);
                j = table[j];
            }else{
                j++;
            }
        }
    }

    return findAt;
}

void output(vector<int> findAt){
    int patSize = pattern.size();

    for(auto& start: findAt){
        cout << "found pattern at index :" << start << '\n';
        int end = start + patSize;
        string format = text.substr(0, start) + "|" + pattern + "|" + text.substr(end);
        cout << format << "\n\n";
    }
}

void solution(){
    input();
    output(kmp(text, pattern));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}