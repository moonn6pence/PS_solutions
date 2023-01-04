#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

vector<pii> init(vector<string> timetable){
    vector<pii> hm;
    for(auto time : timetable){
        hm.push_back({stoi(time.substr(0,2)), stoi(time.substr(3,2))});
    }
    sort(hm.begin(), hm.end());
    
    return hm;
}

pii addTime(pii time1, pii time2){
    pii ret = {time1.first + time2.first, time1.second + time2.second};
    if (ret.second > 59){
        ret.first++;
        ret.second -= 60;
    }
    
    return ret;
}

pii subTime(pii time1, pii time2){
    pii ret = {time1.first - time2.first, time1.second - time2.second};
    if (ret.second < 0){
        ret.first--;
        ret.second += 60;
    }
    
    return ret;
}

string pairToString(pii time){
    string ret = "";
    
    if(time.first < 10) ret += "0";
    ret += to_string(time.first) + ":";
    if(time.second < 10) ret += "0";
    ret += to_string(time.second);
    
    return ret;
}

string solve(int n, int t, int m, vector<pii> timetable){
    int busOrder = 0;
    int top = 0;
    pii interval = {t / 60, t % 60}, last;
    pii curTime = {9, 0};
    
    while (++busOrder){
        int count = m;
        last = curTime;
        
        while (count--){
            if (top >= timetable.size()) {
                if(busOrder == n) return pairToString(curTime);
                break;
            }
            pii diff = subTime(timetable[top], curTime);
            if (diff.first < 0 || (diff.first == 0 && diff.second == 0)){
                last = subTime(timetable[top++], {0, 1});
            } else break;
        }
        
        if(busOrder == n) break;
        curTime = addTime(curTime, interval);
    }
    
    
    return pairToString(last);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    answer = solve(n, t, m, init(timetable));
    return answer;
}