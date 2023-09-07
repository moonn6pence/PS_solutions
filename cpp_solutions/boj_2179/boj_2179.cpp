#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;
vector<string> words;
vector<string> candidates;
unordered_map<string, vector<int>> lookup;

void solution(){

    int max_prefix_len = 0;

    cin >> N;

    for (int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        words.push_back(tmp);

        for (int j = 1; j <= tmp.length(); j++){

            string prefix = tmp.substr(0,j);

            if (max_prefix_len <= prefix.length()){

                if (lookup[prefix].size() == 0){
                    lookup[prefix].push_back(i);
                } else if (lookup[prefix].size() == 1){

                    if (max_prefix_len < prefix.length()) {
                        max_prefix_len = prefix.length();
                        candidates.clear();
                    }

                    lookup[prefix].push_back(i);
                    candidates.push_back(prefix);
                }
            }
        }
    }

    vector<pii> answer;

    for(string str : candidates) {
        answer.push_back({lookup[str][0], lookup[str][1]});
    }

    sort(answer.begin(), answer.end());

    cout << words[answer[0].first] << '\n' << words[answer[0].second];
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    solution();
}