#include <string>
#include <vector>

using namespace std;
int sum = 0;

int dfs(vector<int> numbers,int n,int target){
    if(n >= numbers.size()){
        if(sum == target) return 1;
        return 0;
    }
    int ret = 0;
    
    
    sum += numbers[n];
    ret += dfs(numbers,n+1,target);
    sum -= numbers[n]*2;
    ret += dfs(numbers,n+1,target);
    sum += numbers[n];
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, 0, target);
    return answer;
}