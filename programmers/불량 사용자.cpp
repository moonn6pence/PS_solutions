#include <string>
#include <vector>
#include <regex>
#include <set>

using namespace std;

int N, M;
bool isMatched[8][8] = {false,};
set<string> candidates;

regex getRegex(string id){
    string pattern = regex_replace(id, regex("\\*"), "[a-z0-9]");
    regex re(pattern);

    return re;
}

bool ifMatches(string user, string ban){
    if (regex_match(user,getRegex(ban))){
        return true;
    }

    return false;
}

void init(vector<string> user_id, vector<string> banned_id){
    N = user_id.size();
    M = banned_id.size();

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            isMatched[i][j] = ifMatches(user_id[i], banned_id[j]);
        }
    }
}

void backtrack(int j, string mask){
    if(j == M){
        candidates.insert(mask);
        return;
    }

    int ret = 0;
    for (int i = 0; i < N; i++){
        if(mask[i] == '0' && isMatched[i][j]){
            mask[i] = '1';
            backtrack(j + 1, mask);
            mask[i] = '0';
        }
    }

    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    init(user_id, banned_id);
    string mask;
    for (int i = 0; i < N;i++){
        mask += '0';
    }

    backtrack(0, mask);
    int answer = candidates.size();

    return answer;
}