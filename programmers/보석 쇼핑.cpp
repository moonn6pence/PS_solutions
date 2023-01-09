#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
typedef pair<int, int> pii;
int N;

void init(vector<string> gems){
    set<string> tmp;
    for (auto gem : gems) tmp.insert(gem);

    N = tmp.size();
}

vector<int> solve(vector<string> gems){
    int lo = 0, hi = 0;
    int kind = 1;
    unordered_map<string, int> count;
    vector<int> ret = {100000, 300000};
    if (kind == N) ret = {lo, hi};
    count[gems[0]]++;

    while (lo <= hi && lo < gems.size()){
        if (hi < gems.size() - 1 && kind < N){
            if (count[gems[++hi]] == 0) kind++;
            count[gems[hi]]++;
        } else {
            if (count[gems[lo]] == 1) kind--;
            count[gems[lo++]]--;
        }

        if (kind == N && (hi - lo) < (ret[1] - ret[0])){
            ret[0] = lo; ret[1] = hi;
            if ((ret[1] - ret[0]) == N - 1) break;
        }
    }

    ret[0]++; ret[1]++;

    return ret;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    init(gems);
    answer = solve(gems);
    return answer;
}