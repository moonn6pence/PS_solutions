#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int cnt[100001];

string trim(string str){
    if (str.find('{') != string::npos) str.erase(0, 1);
    if (str.find('}') != string::npos) str.erase(str.size() - 1);

    return str;
}

vector<string> split(string str, char delimiter){
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }

    return result;
}

void countTuple(vector<int> set){
    for(int i = 0; i < set.size(); i++){
        cnt[set[i]]++;
    }
}

vector<int> solve(vector<string> sets){
    vector<int> ret;
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < sets.size(); i++){
        vector<int> set;
        for (auto iter : split(trim(sets[i]), ' ')){
            set.push_back(stoi(iter));
        }
        countTuple(set);
    }

    for (int i = 0; i < 100001; i++){
        if(!cnt[i]) continue;

        pq.push({cnt[i], i});
    }

    while (!pq.empty()){
        ret.push_back(pq.top().second);
        pq.pop();
    }

    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    answer = solve(split(trim(s), ','));
    return answer;
}