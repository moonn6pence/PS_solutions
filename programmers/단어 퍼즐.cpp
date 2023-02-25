#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 2e9;
int cache[20001];
int MIN_LEN = INF;

bool cmp(string s1, string s2){
    return s1.size() < s2.size();
}

int solve(vector<string>& strs, string& s, int idx){
    
    if(idx == -1) return 0;
    
    int& ret = cache[idx];
    
    if (ret != -1) return ret;
    
    ret = INF;
    
    for(int i = 0; i < strs.size(); i++){
        int size = strs[i].size();
        int begin = idx - size + 1;
        if (begin < 0) continue;
        
        bool flag = false;
        for(int j=0;j<size;j++){
            if(s[begin+j] != strs[i][j]){
                flag = true;
                break;
            }
        }
        
        if(flag) continue;
        
        ret = min(ret, solve(strs, s, begin - 1) + 1);
    }
    
    return ret;
}

void preprocess(vector<string>& strs, string& t){
    auto iter = strs.begin();
    
    while(iter != strs.end()){
        if(t.find(*iter) == string::npos){
            iter = strs.erase(iter);
            continue;
        }
        
        MIN_LEN = min(MIN_LEN, (int)(*iter).size());
        iter++;
    }
    
    if (MIN_LEN == INF) return;
    
    for(int i = 0 ; i < MIN_LEN - 1; i++){
        cache[i] = 0;
    }
    
    // sort(strs.begin(), strs.end(), cmp);
}

int solution(vector<string> strs, string t)
{
    fill_n(&cache[0], t.size(), -1);
    preprocess(strs, t);
    int answer = solve(strs, t, t.size() - 1);
    
    if (answer < INF) return answer;
    return -1;
}